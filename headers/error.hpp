// array errors - P. Ahrenkiel

#ifndef _ERROR_
#define _ERROR_

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

#endif
