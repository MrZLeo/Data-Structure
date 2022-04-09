#ifndef __TIME_SCHED_H__
#define __TIME_SCHED_H__

#include <algorithm>
#include <iostream>
#include <vector>

namespace alog {

inline double min_sched_time(std::vector<int> t)
{
    std::sort(t.begin(), t.end());
    int avg = 0;
    int pre = 0;

    for (const auto& iter : t) {
        avg += pre + iter;
        pre += iter;
        /* std::cout << "avg = " << avg << std::endl; */
    }

    return (double)avg / t.size();
}

} // namespace alog
#endif
