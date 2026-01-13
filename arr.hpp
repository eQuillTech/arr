// arrays - P. Ahrenkiel

#ifndef _ARR_
#define _ARR_

#include <iostream>

namespace arr {

inline int err=0;
inline int check_err()
{
    int res = err;
    err = 0;
    return res;
}

inline void clear_err(){ err = 0; }

} // namespace arr

#include "arr1.hpp"
#include "arr2.hpp"
#include "arr3.hpp"
#include "arr2slice.hpp"
#include "arr2sub.hpp"
#include "dbl1.hpp"
#include "dbl2.hpp"
#include "dbl2slice.hpp"
#include "dbl2sub.hpp"
#include "uint1.hpp"
#include "uint2.hpp"
#include "bool1.hpp"
#include "bool2.hpp"
#include "bool3.hpp"
#include "dbl2slice.hpp"
#include "dbl2sub.hpp"
#include "bool2slice.hpp"
#include "bool2sub.hpp"

#endif
