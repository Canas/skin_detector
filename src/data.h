#include <tuple>
#include <string.h>

using namespace std;

tuple<double, double, double> getMean(int id, int kernel);
tuple<double, double, double> getCov(int id, int kernel);
double getWeight(int id, int kernel);
string getImage(int id);