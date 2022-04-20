#ifndef __QUEEN_H__
#define __QUEEN_H__

#include <cstdlib>
#include <iostream>
#include <vector>

static int cnt = 0;

inline bool place(const std::vector<int> &col, int row)
{
    for (int i = 0; i < row; ++i) {
        if (col[i] == col[row]
            || std::abs(col[i] - col[row]) == std::abs(i - row)) {
            return false;
        }
    }

    return true;
}

inline void show_col(const std::vector<int> &col)
{
    cnt++;
    std::cout << "Solution: ";
    for (const auto &iter : col) {
        std::cout << iter + 1 << " ";
    }
    std::cout << std::endl;
}

void queen(const int n)
{
    int row = 0;
    std::vector<int> col = std::vector(n, -1);

    while (row >= 0) {
        col[row]++;
        while (col[row] < n && !place(col, row)) {
            col[row]++;
        }
        // if we can put a queen in this row
        if (col[row] < n) {
            // if it is the last row
            if (row == n - 1)
                show_col(col);
            else {
                row++;
                col[row] = -1;
            }
        } else {
            // can not place, back to last row
            row--;
        }
    }

    std::cout << "cnt = " << cnt << std::endl;
}

#endif // __QUEEN_H__
