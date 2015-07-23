Skin Detection using Mixture of Gaussians
=========================================
This code implements the Jones & Rehg algorithm in C++ using OpenCV 2.4.9. The code was originally developed as a homework for a Computer Vision course so it possesses no optimizations whatsoever and focused solely on working as intended.

Notes
-----
- The code is intended to for use with the data available here (www.cec.uchile.cl/~crsilva/projects/skindetector/data.rar).
- The tools folder contains some Matlab functions that can process the output of the program to plot a ROC curve and analize the effectiveness of the code.

Instructions
------------
After compiling, the program has two ways of executing:
	skin_detector demo
	skin_detector imFile



References
----------
Jones, M.J.; Rehg, J.M., "Statistical color models with application to skin detection," Computer Vision and pattern Recognition, 1999. IEEE Computer Society Conference on. , vol.1, no., pp.,280 Vol. 1, 1999

Credits and licensing
---------------------
Author: Cristobal Silva, crsilva at ing dot uchile dot cl

----------------------------------------------
Detector de Piel:
- main.cpp : Programa principal
- data.cpp/data.h : Funciones que entregan datos de modelo MoG y Nombre de Imagen de la BD

El programa recorre las 45 imagenes de la base de datos y genera 45 archivos ROCdata_{nº de imagen}, ademas de entregar 45 imagenes test_{nº de imagen} con las detecciones de piel para un umbral Theta = 1.

Si se desea revisar una sola imagen, se debe eliminar el loop for para la variable (int im) y generar un único (int im) con el número de la imagen desea (int im=1 para la imagen 0024)

----------------------------------------------
En  caso de problemas, se entregan en un .rar los 45 archivos de datos e imagenes generados por el codigo.
----------------------------------------------

Curvas ROC:
- importROCdata.m : Importa los datos de los archivos ROCdata_{}.txt
- ROC.m : Funcion que grafica curvas ROC y separa para umbrales mayores y menores a 1;
- plotROCgeneral : Grafica en una Figura los 45 ROC y en otra Figura el ROC promedio de las 45 imagenes.