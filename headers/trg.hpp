// math - P. Ahrenkiel

#ifndef _TRG_
#define _TRG_

#include <cstdlib>
#include <math.h>

namespace trg {

const double Pi(4. * atan(1.));
const double degtorad(180. / Pi);

//
double asincos(double s, double c)
{
    double a = acos(c);
    if (s < 0.)
        a *= -1.;
    return a;
}

//
double asintan(double s, double t) { return asincos(s, acos(s / t)); }

//
double acossin(double c, double s) { return asincos(s, c); }

//
double acostan(double c, double t) { return asincos(c * t, c); }

//
double atansin(double t, double s) { return asincos(s, acos(s / t)); }

//
double atancos(double t, double c) { return asincos(c * t, c); }

//
double sinc(double x)
{
    if (fabs(x) < 1.e-10)
        return 1.;
    return sin(x) / x;
}

} // namespace trg
#endif
