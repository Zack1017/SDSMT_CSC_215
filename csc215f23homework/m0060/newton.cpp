#include "newton.h"
#include "..\\catch_amalgamated.cpp"

double newtonApprox ( double n, function < double ( double ) > x, function < double ( double ) > y, double epsilon )
{
    double k = n - x ( n ) / y ( n );
    if ( fabs ( k - n ) < epsilon )
    {
        return k;
    }
    return newtonApprox( k, x, y, epsilon );
} 