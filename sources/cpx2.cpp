/*
Complex 2-D Arrays - P. Ahrenkiel
*/

#include <cstdlib>
#include <math.h>

#include "tlbx.hpp"
#include "error.hpp"
#include "cpx1.hpp"
#include "cpx2.hpp"
#include "dbl2.hpp"

namespace arr {

cpx2 cpx2::operator+() const
{
	return *this;
}

cpx2 cpx2::operator-() const
{
	cpx2 res(*this);
	for(std::size_t i=0;i<size(0);++i)
		for(std::size_t j=0;j<size(1);++j)
			res(i,j)*=-1;
	return res;
}

cpx2 cpx2::operator+(const cpx2 &A) const
{
	cpx2 res(*this);
	for(std::size_t i=0;i<size(0);++i)
		for(std::size_t j=0;j<size(1);++j)
			res(i,j)+=A(i,j);
	return res;
}

cpx2 cpx2::operator-(const cpx2 &A) const
{
	cpx2 res(*this);
	for(std::size_t i=0;i<size(0);++i)
		for(std::size_t j=0;j<size(1);++j)
			res(i,j)-=A(i,j);
	return res;
}

cpx2 cpx2::operator+=(const cpx2 &A)
{	
	return *this=*this+A;
}

cpx2 cpx2::operator-=(const cpx2 &A)
{
	return *this=*this-A;
}

cpx2 cpx2::operator/(cpx x) const
{
	return (1./x)*(*this);
}

cpx2 cpx2::operator*=(cpx x)
{
	return *this=x*(*this);
}

cpx2 cpx2::operator/=(cpx x)
{
	return *this=(*this)/x;
}

cpx2 cpx2::operator/(double x) const
{
	return (1./x)*(*this);
}

cpx2 cpx2::operator*=(double x)
{
	return *this=x*(*this);
}

cpx2 cpx2::operator/=(double x)
{
	return *this=(*this)/x;
}

cpx1 cpx2::operator*(const cpx1 &A) const
{
	size_t i,j;
	cpx1 res(size(0));
	for(i=0;i<size(0);++i)
	{
		cpx x=0.;
		for(j=0;j<size(1);++j)
			x+=(*this)(i,j)*A(j);
		res(i)=x;
	}
	return res;
}

cpx2 cpx2::operator*(const cpx2 &A) const
{
	size_t i,j,k;
	cpx2 res(size(0),A.size(1));
	for(i=0;i<res.size(0);++i)
		for(j=0;j<res.size(1);++j)
		{
			cpx x=0.;
			for(k=0;k<size(1);++k)
				x+=(*this)(i,k)*A(k,j);
			res(i,k)=x;
		}
	return res;
}

cpx2 cpx2::inverse() const
{
	cpx2 res(size(1),size(0));
	if(!isSquare())
	{
		err=-1;
		return res;
	}

	return adjugate()/det();
}

cpx2 cpx2::diagonal() const
{
	cpx2 res(size(0),size(1));
	for(std::size_t i = 0; i<size(0); ++i)
		for(std::size_t j = 0; j<size(1); ++j)
			res(i,j)=mth::Kdelta(i,j)*(*this)(i,j);
	return res;
}

cpx2 cpx2::pseudoinverse_left() const
{
	cpx2 AT=T();
	cpx2 res=(AT*(*this)).inverse()*AT;
	return res;
}

cpx2 cpx2::pseudoinverse_right() const
{
	cpx2 AT=T();
	cpx2 res=AT*(((*this)*AT).inverse());
	return res;
}

cpx2 cpx2::damped_pseudoinverse_left(double lambda) const
{
	cpx2 Ap=(*this)+lambda*diagonal();
	return Ap.pseudoinverse_left();
}

cpx2 cpx2::minor(size_t m,size_t n) const
{
	cpx2 res(size(0)-1,size(0)-1);
	size_t i,j,ip,jp;
	ip=0;
	for(i=0;i<size(0);++i)
		if(i!=m)
		{
			jp=0;
			for(j=0;j<size(0);++j)
				if(j!=n)
				{
					res(ip,jp)=(*this)(i,j);
					++jp;
				}
		++ip;
		}

	return res;
}

cpx2 cpx2::cofactor() const
{
	cpx2 res(size(0),size(0));
	size_t i,j;
	for(i=0;i<size(0);++i)
		for(j=0;j<size(0);++j)
				res(i,j)=cos((i+j)*trg::pi)*minor(i,j).det();
	return res;
}

cpx2 cpx2::adjugate() const
{
	return cofactor().T();
}

cpx cpx2::det() const
{
	if(size(0)>1)
	{
		cpx res=0.;
		size_t j;
		//cpx2 temp(size(0)-1,size(0)-1);
		for(j=0;j<size(0);++j)
		{
			cpx2 temp=minor(0,j);				
			cpx del=cos(j*trg::pi)*(*this)(0,j)*(temp).det();
			res+=del;
		}
		return res;
	}
	else
		return (*this)(0,0);
}

cpx2 operator*(const double x,const cpx2 &A) 
{
	cpx2 res(A);
	size_t i,j;
	for(i=0;i<A.size(0);++i)
		for(j=0;j<A.size(1);++j)
			res(i,j)=x*A(i,j);
	return res;
}

cpx2 operator*(const cpx C,const cpx2 &A)
{
	cpx2 res(A);
	size_t i,j;
	for(i=0;i<A.size(0);++i)
		for(j=0;j<A.size(1);++j)
			res(i,j)=C*A(i,j);
	return res;
}

std::ostream& operator<<(std::ostream &os,const cpx2 &A)
{
	size_t i,j;
	for(i=0;i<A.size(0);++i)
	{
		for(j=0;j<A.size(1);++j)
		{
			if(j>0)os<<"\t";
			os<<A(i,j);
		}
		os<<std::endl;
	}
	return os;
}

}
