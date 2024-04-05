//bool arrays (n) - P. Ahrenkiel

#include <cstdlib>
#include <math.h>

#include "tlbx.hpp"
#include "arr.hpp"

using namespace std;

//
barr1 barr1::zero(const size_t n)
{
	barr1 res(n);
	res=false;
	return res;
}

//
barr1 barr1::operator|(const barr1 &b) const
{
	size_t n=std::min(m_n,b.size());
	barr1 res=(m_n<b.size())?b:*this;
	for(size_t i=0;i<n;i++)
		res(i)=at(i)|b(i);
	return res;
}

//
barr1 barr1::operator&(const barr1 &b) const
{
	size_t n=std::min(m_n,b.size());
	barr1 res=(m_n>b.size())?b:*this;
	for(size_t i=0;i<n;i++)
		res(i)=at(i)&b(i);
	return res;
}

//
barr1 &barr1::operator|=(const barr1 &b)
{
	return *this=(*this)|b;
}

//
barr1 &barr1::operator&=(const barr1 &b)
{
	return *this=(*this)&b;
}

//
bool barr1::hasTrue()const
{
	for(size_t i=0;i<size();i++)
		if(at(i))return true;
	return false;
}

//
bool barr1::hasFalse()const
{
	for(size_t i=0;i<size();i++)
		if(!at(i))return true;
	return false;
}

//friend
ostream& operator<<(ostream &os,const barr1 &A)
{
	cout<<"(";
	for(size_t i=0;i<A.size();++i)
	{
		if(i>0)cout<<"\t";
		if(A(i))cout<<"T";
		else cout<<"F";
	}
	cout<<")";
	return os;
}
