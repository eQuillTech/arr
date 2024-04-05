//arrays - P. Ahrenkiel

#include "tlbx.hpp"
#include "arr.hpp"

int arr_err=0;

//
int check_arr_err()
{
	int res=arr_err;
	arr_err=0;
	return res;
}

//
void clear_arr_err()
{
	arr_err=0;
}
