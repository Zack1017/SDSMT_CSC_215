#include <cmath>
#include <functional>

using namespace std;

double newtonApprox(double n, function<double(double)> x, function<double(double)> y, double epsilon);