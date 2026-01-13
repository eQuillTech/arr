/*
Complex Arrays: Rank 1- P. Ahrenkiel
*/

#ifndef _CPX1
#define _CPX1

#include <iostream> 

#include "arr1.hpp"
#include "cpx.hpp"

namespace arr {

typedef arr1<cpx> cpx_arr1;

class cpx1:public cpx_arr1
{
private:
	
public:
	cpx1(const std::size_t n=0,const cpx* ap=NULL):cpx_arr1(n,ap) {}
	cpx1(const cpx_arr1& A):cpx_arr1(A.size(),A.data()) {}
	cpx1(const dbl1& A);

	cpx1 operator+() const;
	cpx1 operator-() const;
	cpx1 operator+(const cpx1 &A) const;
	cpx1 operator-(const cpx1 &A) const;
	cpx1 operator+=(const cpx1 &A);
	cpx1 operator-=(const cpx1 &A);
	cpx1 operator/(const cpx &C) const;
	cpx operator*(const cpx1 &A) const;
	cpx1 operator*=(const cpx &C);
	cpx1 operator/=(const cpx &C);

	double mag() const;
	double magsqr() const;
	cpx1 conj() const;
	dbl1 Re() const;
	dbl1 Im() const;
	cpx1 norm() const{return (*this)/mag();}

	cpx operator*(const dbl1 &A);

	cpx1 operator/(double x) const{return (*this)/cpx(x);}
	cpx1 operator*=(double x){return (*this)*=cpx(x);}
	cpx1 operator/=(double x){return (*this)/=cpx(x);}

	friend dbl1 Re(const cpx1 &A){return A.Re();}
	friend dbl1 Im(const cpx1 &A){return A.Im();}
	friend cpx1 norm(const cpx1 &A){return A.norm();}

	friend cpx1 operator*(const cpx &C,const cpx1 &A);
	friend cpx1 operator*(const double x,const cpx1 &A){return cpx(x)*A;}

	//mixed versions
	friend cpx operator*(const dbl1 &A1,const cpx1 &A2){return cpx1(A1)*A2;}
	friend cpx1 operator/(const dbl1 &A,const cpx &C){return (1./C)*cpx1(A);}
	friend cpx1 operator+(const dbl1 &A1,const cpx1 &A2){return cpx1(A1)+A2;}
	friend cpx1 operator-(const dbl1 &A1,const cpx1 &A2){return cpx1(A1)-A2;}
	friend cpx1 operator*(const cpx &C,const dbl1 &A);

	friend std::ostream& operator<<(std::ostream &os,const cpx1 &A);
};

cpx1 operator*(const cpx &C,const dbl1 &A);
} // namespace arr

#endif
