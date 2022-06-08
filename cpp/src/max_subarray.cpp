#include <iostream>
#include <vector>

using namespace std;

struct ret {
    int l;
    int r;
    int sum;
};

ret crossing(vector<int> A, int l, int mid, int r)
{
    int ls = INT32_MIN;
    int sum = 0;
    int li = mid;
    for (int i = mid; i >= 0; --i) {
        sum += A[i];
        if (sum > ls) {
            ls = sum;
            li = i;
        }
    }
    int rs = INT32_MIN;
    int ri = mid + 1;
    sum = 0;
    for (int i = mid + 1; i < A.size(); ++i) {
        sum += A[i];
        if (sum > rs) {
            rs = sum;
            ri = i;
        }
    }

    return ret { .l = li, .r = ri, .sum = ls + rs };
}

ret max_sub(vector<int> A, int l, int r)
{
    if (l == r)
        return ret { .l = l, .r = r, .sum = A[l] };

    int mid = l + (r - l) / 2;
    ret rl = max_sub(A, l, mid);
    ret rr = max_sub(A, mid + 1, r);
    ret rm = crossing(A, l, mid, r);

    if (rl.sum > rr.sum && rl.sum > rm.sum)
        return rl;
    if (rr.sum > rl.sum && rr.sum > rm.sum)
        return rr;
    return rm;
}

int test()
{
    auto A = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    ret r = max_sub(A, 0, 15);
    cout << r.l << " " << r.r << " " << r.sum << endl;
    return 0;
}
