#ifndef __UTIL_H__
#define __UTIL_H__

#include <sstream>
#include <string>

template<typename T>
std::string xtos(T t) {
    std::stringstream s;
    s << t;
    return s.str();
}

#endif // __UTIL_H__
