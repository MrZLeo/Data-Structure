#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <graph_util.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class WeightedGraph {

private:
    int e;
    int v;
    std::vector<std::unordered_map<int, int>> adj;

public:
    WeightedGraph(std::string filename)
        : v(0)
        , e(0)
    {
        std::ifstream in;
        in.open(filename);
        in >> v >> e;
        adj = std::vector(v, std::unordered_map<int, int>());
        int x, y, weight;
        while (in >> x >> y >> weight) {
            adj[x][y] = weight;
        }
    }

    /**
     * @arg s: the source point
     * @return shortest path that s to other point
     */
    std::vector<int> bellman_ford(int s)
    {
        std::vector<int> dis = std::vector(v, INT32_MAX);
        std::vector<int> pre = std::vector(v, INT32_MAX);

        dis[s] = 0;

        // do `v - 1` times relaxation inorder to find all shortest path surely
        for (int pass = 1; pass < v; ++pass) {

            // to each edge, do the relaxation
            for (int i = 0; i < v; ++i) {
                for (const auto &u : adj[i]) {
                    if (dis[i] < INT32_MAX
                        && dis[i] + u.second < dis[u.first]) {
                        dis[u.first] = dis[i] + u.second;
                        pre[u.first] = i;
                    }
                }
            }
        }

        // check whether has negative cycle
        for (int i = 0; i < v; ++i) {
            for (const auto &u : adj[i]) {
                if (dis[i] < INT32_MAX
                    && dis[i] + u.second < dis[u.first]) {
                    // has negative cycle
                    // return INT32_MAX to indicate error
                    std::cout << "\x1b[31m[ERROR] Negative Cycle Detected\x1b[0m\n";
                    return std::vector<int>(v, INT32_MAX);
                }
            }
        }

        // print the path
        for (int i = 0; i < v; ++i) {
            graph_util::print_path(pre, s, i);
        }

        return dis;
    }

    /**
     * @return all pair shortest path
     */
    std::vector<std::vector<int>> floyd()
    {
        std::vector<std::vector<int>> dis = std::vector(v, std::vector(v, INT32_MAX));

        for (int i = 0; i < v; ++i) {
            dis[i][i] = 0;
            for (const auto &w : adj[i]) {
                dis[i][w.first] = w.second;
            }
        }

        for (int t = 0; t < v; ++t) {
            for (int w = 0; w < v; ++w) {
                for (int u = 0; u < v; ++u) {
                    if (dis[w][t] < INT32_MAX
                        && dis[t][u] < INT32_MAX
                        && dis[w][t] + dis[t][u] < dis[w][u]) {
                        dis[w][u] = dis[w][t] + dis[t][u];
                    }
                }
            }
        }

        // detect negative cycle
        for (int i = 0; i < v; ++i) {
            if (dis[i][i] < 0) {
                // has negative cycle
                // return INT32_MAX to indicate error
                std::cout << "\x1b[31m[ERROR] Negative Cycle Detected\x1b[0m\n";
                return std::vector(v, std::vector(v, INT32_MAX));
            }
        }

        return dis;
    }
};

#endif // __GRAPH_H__
