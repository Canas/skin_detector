#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <string.h>

using namespace std;

tuple<double, double, double> getMean(int id, int kernel){
	switch (id){
	case 1: // SKIN MoG color model
		if (kernel == 1)  return make_tuple(17.76, 29.94, 73.53);
		if (kernel == 2)  return make_tuple(217.49, 233.94, 249.71);
		if (kernel == 3)  return make_tuple(96.95, 116.25, 161.68);
		if (kernel == 4)  return make_tuple(114.40, 132.62, 186.07);
		if (kernel == 5)  return make_tuple(51.58, 98.37, 189.26);
		if (kernel == 6)  return make_tuple(90.84, 152.20, 247.00);
		if (kernel == 7)  return make_tuple(37.76, 72.66, 150.10);
		if (kernel == 8)  return make_tuple(156.34, 171.09, 206.85);
		if (kernel == 9)  return make_tuple(120.04, 152.82, 212.78);
		if (kernel == 10) return make_tuple(138.94, 175.43, 234.87);
		if (kernel == 11) return make_tuple(74.89, 97.74, 151.19);
		if (kernel == 12) return make_tuple(59.82, 77.55, 120.52);
		if (kernel == 13) return make_tuple(82.32, 119.62, 192.20);
		if (kernel == 14) return make_tuple(87.24, 136.08, 214.29);
		if (kernel == 15) return make_tuple(38.06, 54.33, 99.57);
		if (kernel == 16) return make_tuple(176.91, 203.08, 238.88);

	case 2: // NON-SKIN MoG color model
		if (kernel == 1)  return make_tuple(253.82, 254.41, 254.37);
		if (kernel == 2)  return make_tuple(8.52, 8.09, 9.39);
		if (kernel == 3)  return make_tuple(96.57, 96.95, 91.53);
		if (kernel == 4)  return make_tuple(159.06, 162.49, 160.44);
		if (kernel == 5)  return make_tuple(46.33, 63.23, 74.98);
		if (kernel == 6)  return make_tuple(18.31, 60.88, 121.83);
		if (kernel == 7)  return make_tuple(91.04, 154.88, 202.18);
		if (kernel == 8)  return make_tuple(206.55, 201.93, 193.06);
		if (kernel == 9)  return make_tuple(61.55, 57.14, 51.88);
		if (kernel == 10) return make_tuple(25.32, 26.84, 30.88);
		if (kernel == 11) return make_tuple(131.95, 85.96, 44.97);
		if (kernel == 12) return make_tuple(230.70, 236.27, 236.02);
		if (kernel == 13) return make_tuple(164.12, 191.20, 207.86);
		if (kernel == 14) return make_tuple(188.17, 148.11, 99.83);
		if (kernel == 15) return make_tuple(123.10, 131.92, 135.06);
		if (kernel == 16) return make_tuple(66.88, 103.89, 135.96);
	
	default:
		cout << "ID = 1 o 2" << endl; return make_tuple(0.0, 0.0, 0.0);
	}
}

tuple<double, double, double> getCov(int id, int kernel){
	switch (id){
	case 1: // SKIN MoG color model
		if (kernel == 1)  return make_tuple(112.80, 121.44, 765.40);
		if (kernel == 2)  return make_tuple(396.05, 154.44, 39.94);
		if (kernel == 3)  return make_tuple(162.85, 60.48, 291.03);
		if (kernel == 4)  return make_tuple(198.27, 64.60, 274.95);
		if (kernel == 5)  return make_tuple(250.69, 222.40, 633.18);
		if (kernel == 6)  return make_tuple(609.92, 691.53, 65.23);
		if (kernel == 7)  return make_tuple(257.57, 200.77, 408.63);
		if (kernel == 8)  return make_tuple(572.79, 155.08, 530.08);
		if (kernel == 9)  return make_tuple(243.90, 84.52, 160.57);
		if (kernel == 10) return make_tuple(279.22, 121.57, 163.80);
		if (kernel == 11) return make_tuple(175.11, 73.56, 425.40);
		if (kernel == 12) return make_tuple(151.82, 70.34, 330.45);
		if (kernel == 13) return make_tuple(259.15, 92.14, 152.76);
		if (kernel == 14) return make_tuple(270.19, 140.17, 204.90);
		if (kernel == 15) return make_tuple(151.29, 90.18, 448.13);
		if (kernel == 16) return make_tuple(404.99, 156.27, 178.38);

	case 2: // NON-SKIN MoG color model
		if (kernel == 1)  return make_tuple(5.46, 2.81, 2.77);
		if (kernel == 2)  return make_tuple(32.48, 33.59, 46.84);
		if (kernel == 3)  return make_tuple(436.58, 156.79, 280.69);
		if (kernel == 4)  return make_tuple(591.24, 115.86, 355.98);
		if (kernel == 5)  return make_tuple(361.27, 245.95, 414.84);
		if (kernel == 6)  return make_tuple(237.18, 1383.53, 2502.24);
		if (kernel == 7)  return make_tuple(1582.52, 1766.94, 957.42);
		if (kernel == 8)  return make_tuple(447.28, 190.23, 562.88);
		if (kernel == 9)  return make_tuple(433.40, 191.77, 344.11);
		if (kernel == 10) return make_tuple(182.41, 118.65, 222.07);
		if (kernel == 11) return make_tuple(963.67, 840.52, 651.32);
		if (kernel == 12) return make_tuple(331.95, 117.29, 225.03);
		if (kernel == 13) return make_tuple(533.52, 237.69, 494.04);
		if (kernel == 14) return make_tuple(916.70, 654.95, 955.88);
		if (kernel == 15) return make_tuple(388.43, 130.30, 350.35);
		if (kernel == 16) return make_tuple(350.36, 642.20, 806.44);
	
	default:
		cout << "ID = 1 o 2" << endl; return make_tuple(0.0, 0.0, 0.0);
	}
}

double getWeight(int id, int kernel){
	switch (id){
	case 1: // SKIN MoG color model
		if (kernel == 1)  return 0.0294;
		if (kernel == 2)  return 0.0331;
		if (kernel == 3)  return 0.0654;
		if (kernel == 4)  return 0.0756;
		if (kernel == 5)  return 0.0554;
		if (kernel == 6)  return 0.0314;
		if (kernel == 7)  return 0.0454;
		if (kernel == 8)  return 0.0469;
		if (kernel == 9)  return 0.0956;
		if (kernel == 10) return 0.0763;
		if (kernel == 11) return 0.1100;
		if (kernel == 12) return 0.0676;
		if (kernel == 13) return 0.0755;
		if (kernel == 14) return 0.0500;
		if (kernel == 15) return 0.0667;
		if (kernel == 16) return 0.0749;

	case 2: // NON-SKIN MoG color model
		if (kernel == 1)  return 0.0637;
		if (kernel == 2)  return 0.0516;
		if (kernel == 3)  return 0.0864;
		if (kernel == 4)  return 0.0636;
		if (kernel == 5)  return 0.0747;
		if (kernel == 6)  return 0.0365;
		if (kernel == 7)  return 0.0349;
		if (kernel == 8)  return 0.0649;
		if (kernel == 9)  return 0.0656;
		if (kernel == 10) return 0.1189;
		if (kernel == 11) return 0.0362;
		if (kernel == 12) return 0.0849;
		if (kernel == 13) return 0.0368;
		if (kernel == 14) return 0.0389;
		if (kernel == 15) return 0.0943;
		if (kernel == 16) return 0.0477;

	default:
		cout << "ID = 1 o 2" << endl; return 0.0;
	}
}

string getImage(int id){
	switch (id){
	case 1: return "0024";
	case 2: return "0119";
	case 3: return "0121";
	case 4: return "0125";
	case 5: return "0159";
	case 6: return "0178";
	case 7: return "0179";
	case 8: return "0180";
	case 9: return "0183";
	case 10: return "0184";
	case 11: return "0185";
	case 12: return "0200";
	case 13: return "0201";
	case 14: return "0223";
	case 15: return "0228";
	case 16: return "0232";
	case 17: return "0237";
	case 18: return "0245";
	case 19: return "0270";
	case 20: return "0273";
	case 21: return "0281";
	case 22: return "0293";
	case 23: return "0294";
	case 24: return "0295";
	case 25: return "0296";
	case 26: return "0307";
	case 27: return "0313";
	case 28: return "0315";
	case 29: return "0323";
	case 30: return "0327";
	case 31: return "0352";
	case 32: return "0359";
	case 33: return "0396";
	case 34: return "0397";
	case 35: return "0428";
	case 36: return "0466";
	case 37: return "0491";
	case 38: return "0515";
	case 39: return "0517";
	case 40: return "0522";
	case 41: return "0523";
	case 42: return "0538";
	case 43: return "0539";
	case 44: return "0540";
	case 45: return "0550";
	}
}