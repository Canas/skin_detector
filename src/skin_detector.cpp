#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <fstream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "data.h"

using namespace std;
using namespace cv;

double gaussianMixture(int id, tuple<double,double,double> RGBpixel){

	double P = 0;
	double C, D, covDet;
	double a[3], mean[3], covDiag[3], w;

	for (int i = 1; i <= 16; i++){
		mean[0] = get<0>(getMean(id, i)); mean[1] = get<1>(getMean(id, i)); mean[2] = get<2>(getMean(id, i)); // Media
		covDiag[0] = get<0>(getCov(id, i)); covDiag[1] = get<1>(getCov(id, i)); covDiag[2] = get<2>(getCov(id, i)); //Diagonal de Matriz de Covarianza
		w = getWeight(id, i);

		a[0] = (get<0>(RGBpixel)) - mean[0]; a[1] = (get<1>(RGBpixel)) - mean[1]; a[2] = (get<2>(RGBpixel)) - mean[2]; // x - u

		covDet = covDiag[0] * covDiag[1] * covDiag[2];	// determinante de Covarianza o Det(Cov)
		C = pow(2 * M_PI, 1.5)*pow(covDet, 0.5);		// 1/[(2*pi)^(3/2) * Det(Cov)^(1/2)]
		D = -0.5*(pow(a[0], 2) / covDiag[0] + pow(a[1], 2) / covDiag[1] + pow(a[2], 2) / covDiag[2]);	// Termino exponencial

		P = P + (w/C)*exp(D); // Suma i-esima de P(x)
	}
	return P;
}

bool bayesDetect(double P_x_skin, double P_x_noskin, double threshold){
	double rate = P_x_skin / P_x_noskin;	//  Razon entre Verosimilitudes
	bool isSkin;

	if (rate > threshold)	// Si rate > umbral, entonces es Skin
		isSkin = true;
	else
		isSkin = false;

	return isSkin;
}

int call_demo(){
	Mat input1, input2;
	for (int im = 1; im <= 45; im++){
		input1 = imread("data/" + getImage(im) + ".jpg", CV_LOAD_IMAGE_COLOR);
		input2 = imread("data/" + getImage(im) + ".bmp", CV_LOAD_IMAGE_COLOR);

		if (!input1.data || !input2.data){
			cout << "No se pudo cargar imagen" << endl;
			return -2;
		}

		tuple<double, double, double> im1pixel, im2pixel;	//Tuplas que guardaran pixeles

		// Inicializar variables involucradas en el analisis
		double ground_skin = 0;		// N real de pixeles Skin
		double ground_noskin = 0;	// N real de pixeles NoSkin
		double test_skin = 0;		// N detectado de pixeles Skin
		double test_noskin = 0;		// N detectado de pixeles NoSkin
		MatIterator_<Vec3b> it1, end;
		MatIterator_<Vec3b> it2;

		double P_x_skin, P_x_noskin, thres;
		bool test_isSkin, ground_isSkin;

		const int nT = 45;			// N de Umbrales a utilizar
		int a[nT] = { 0 }; int b[nT] = { 0 }; int c[nT] = { 0 }; int d[nT] = { 0 };
		double TPR[nT] = { 0 }; double FPR[nT] = { 0 };

		cout << "Analizando Imagen: " << getImage(im) << endl;
		ofstream myfile("output/rocdata/ROCdata_" + getImage(im) + ".txt");

		for (pair<MatIterator_<Vec3b>, MatIterator_<Vec3b>> i(input1.begin<Vec3b>(), input2.begin<Vec3b>()); i.first != input1.end<Vec3b>(); ++i.first, ++i.second){
			im1pixel = make_tuple((*i.first)[0], (*i.first)[1], (*i.first)[2]);
			im2pixel = make_tuple((*i.second)[0], (*i.second)[1], (*i.second)[2]);

			/* Contar N de Skin / No-Skin verdaderos*/
			if (get<0>(im2pixel) == 255 && get<1>(im2pixel) == 255 && get<2>(im2pixel) == 255){
				ground_noskin++;
				ground_isSkin = false;
			}
			else{
				ground_skin++;
				ground_isSkin = true;
			}

			/* Calcular Probabilidades Condicionales o Verosimilitudes del pixel */
			P_x_skin = gaussianMixture(1, im1pixel);				// P(x/Skin)
			P_x_noskin = gaussianMixture(2, im1pixel);				// P(x/noSkin)

			/* Contar TP, FN, FP, TN para diferentes umbrales */
			for (int k = 0; k < nT; k++){
				if (k <= 20){
					thres = k*0.05;		// Primeros 20 umbrales entre [0,1] con step 0.05
				}
				else{
					thres = thres + 2;	// Siguientes umbrales entre [0,infinito] con step 2
				}

				test_isSkin = bayesDetect(P_x_skin, P_x_noskin, thres);	// Clasificador de Bayes
				if (ground_isSkin == true){
					if (test_isSkin == true)
						a[k]++;	// True Positive  (TP)
					else{
						b[k]++;	// False Negative (FN)
						if (thres == 1){
							(*i.first)[0] = 255; (*i.first)[1] = 255; (*i.first)[2] = 255;	// Borro el pixel noSkin de la imagen original
						}
					}
				}
				else{
					if (test_isSkin == true)
						c[k]++;	// False Positive (FP)
					else{
						d[k]++;	// True Negative  (TN)
						if (thres == 1){
							(*i.first)[0] = 255; (*i.first)[1] = 255; (*i.first)[2] = 255;	// Borro el pixel noSkin de la imagen original
						}
					}
				}

			}
			thres = 0;
		}

		for (int k = 0; k < nT; k++){
			TPR[k] = a[k] / ground_skin;	// Skin detectado dado que era Skin (true positive rate)
			FPR[k] = c[k] / ground_noskin;	// Skin detectado dado que era No-Skin (false positive rate)

			myfile << TPR[k] << " " << FPR[k] << endl;	// Escribir Tasas en ROCdata.txt
		}

		myfile.close();
		imwrite("output/images/out_" + getImage(im) + ".jpg", input1);
	}
}

void call_detector(Mat &image, int thres){
	imshow("Input", image);

	tuple<double, double, double> im1pixel;
	double test_skin = 0;		// N detectado de pixeles Skin
	double test_noskin = 0;		// N detectado de pixeles NoSkin
	MatIterator_<Vec3b> it, end;

	double P_x_skin, P_x_noskin;
	bool test_isSkin;

	cout << "Analizando Imagen" << endl;

	for (MatIterator_<Vec3b> it = image.begin<Vec3b>(); it != image.end<Vec3b>(); ++it){
		im1pixel = make_tuple((*it)[0], (*it)[1], (*it)[2]);

		/* Calcular Probabilidades Condicionales o Verosimilitudes del pixel */
		P_x_skin = gaussianMixture(1, im1pixel);				// P(x/Skin)
		P_x_noskin = gaussianMixture(2, im1pixel);				// P(x/noSkin)

		test_isSkin = bayesDetect(P_x_skin, P_x_noskin, thres);	// Clasificador de Bayes
		
		if (test_isSkin == false){
			(*it)[0] = 255; (*it)[1] = 255; (*it)[2] = 255;	// Borro el pixel noSkin de la imagen original
		}
	}

	imwrite("output.jpg", image);
	imshow("Output", image);
	cout << "Presione ENTER en una ventana o CTRL-C para salir" << endl;
	cvWaitKey(0);
}

int main(int argc, char** argv){

	if(argc == 2){
		if(strcmp(argv[1],"demo")){
			return call_demo();
		}
	}

	else if (argc == 3){
		Mat i = imread(argv[1],CV_LOAD_IMAGE_COLOR);
		if(!i.data){
			cout << "No se pudo cargar la imagen." << endl;
			return -2;
		}
		int t = atoi(argv[2]);
		call_detector(i,t);
	}

	else{
		cout << "Modo de uso:" << endl;
		cout << "1: skin_detector demo" << endl;
		cout << "2: skin_detector image threshold" << endl;
		return -1;
	}

	return 0;
}