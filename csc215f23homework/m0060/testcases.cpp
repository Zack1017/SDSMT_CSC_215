#include "newton.h"
#include "..\catch_amalgamated.hpp"
using namespace Catch;
/*
TEST_CASE("newtonApprox - testing base case")
{
    double epsilon = 2.1;
    double n = 2;
    double ans;
    double f1 = 2;
    double fp1 = 1;
    ans = newtwonApprox(n, f1, fp1, epsilon);
    REQUIRE(fabs(ans) <= epsilon);
}
*/
double f ( double x )
{
    return pow ( x, 3 ) + 2;
}



double fp ( double x )
{
    return 3 * pow ( x, 2 );
}



TEST_CASE ( "newtonApprox - x^3 +2" ) //1
{
    double epsilon = 0.001;
    double n = 2;
    double ans;
    ans = newtonApprox( n, f, fp, epsilon );
    REQUIRE ( fabs ( f ( ans ) ) <= epsilon );
}



double f2 ( double x )
{
    return pow ( x, 2 ) -1;
}



double fp2 ( double x )
{
    return 2 * x;
}



TEST_CASE ( "newtonApprox - x^2 -1" )//2
{
    double epsilon = 0.001;
    double n = 2;
    double ans;
    ans = newtonApprox( n, f2, fp2, epsilon );
    REQUIRE ( fabs ( f2 ( ans ) ) <= epsilon );
}



double f3 ( double x )
{
    return x + 2;
}



double fp3 ( double x )
{
    return 1;
}



TEST_CASE ( "newtonApprox - x+2" )//3
{
    double epsilon = 0.001;
    double n = 2;
    double ans;
    ans = newtonApprox( n, f3, fp3, epsilon );
    REQUIRE ( fabs ( f3 ( ans ) ) <= epsilon );
}



double f4 ( double x )
{
    return pow ( x,5 ) + 20;
}



double fp4 ( double x )
{
    return 5 * pow ( x, 4 );
}



TEST_CASE ( "newtonApprox - x^5 +20" )//4
{
    double epsilon = 0.001;
    double n = 10;
    double ans;
    ans = newtonApprox( n, f4, fp4, epsilon );
    REQUIRE ( fabs ( f4 ( ans ) ) <= epsilon );
}



double f5 ( double x )
{
    return pow ( x, 6 ) -5;
}



double fp5 ( double x )
{
    return 6 * pow ( x, 5 );
}



TEST_CASE ( "newtonApprox - x^6 -5" ) //5
{
    double epsilon = 0.001;
    double n = 2;
    double ans;
    ans = newtonApprox( n, f5, fp5, epsilon );
    REQUIRE ( fabs ( f5 ( ans ) ) <= epsilon );
}


double f6(double x)
{
    return 3 * pow(x, 4) - pow(x,3) + 2 * pow(x,2) - 5 *x -7;
}



double fp6(double x)
{
    return 12 * pow(x,3) - 3 * pow(x,2) + 4 * x - x;
}


/*
TEST_CASE("newtonApprox - 3x^4 - x^3 + 2x^2 - 5x - 7") //6
{
    double epsilon = 0.00001;
    double n = 2;
    double ans;
    ans = newtonApprox(n, f6, fp6, epsilon);
    REQUIRE(fabs(f6(ans)) <= epsilon);
}*/
