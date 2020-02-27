#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

void solve(const int& n, int d, ostream& cout){
    vector<vector<int>> nodes_from(n, vector<int>());
    vector<int> p(n + 1);

    // create a tree with minimum sum of depths
    // (complete all levels from left to right, starting with the first one)
    int min_sum = 0;
    int max_sum = ((n - 1) * n) / 2;
    int level = 1;
    int level_max_node = 3;
    for(int i = 2; i <= n; ++i){
        if(level_max_node < i){
            level_max_node = 2 * level_max_node + 1;
            level += 1;
        }

        p[i] = i / 2;
        min_sum += level;
        nodes_from[level].push_back(i);
    }

    // check if the desired sum of depths d is in the range of possible solutions [min_sum, max_sum]
    if(min_sum <= d && d <= max_sum){
        // update the tree by increasing (step by step) the level of the leafs (nodes from the last levels)
        // always update the leafs from the last level (if level_size>1),
        //        moving from right to left (don't think is mandatory, but for sure is easier to implement)
        // one update <=> increase the sum of depths with one
        // the max sum of depths will correspond to a tree in form of a chain 1 - 2 - .... - n
        int level = 1;
        while(level + 1 < n && nodes_from[level + 1].size() > 0){
            ++level;
        }
        
        int sum = min_sum;
        while(sum < d){
            while(nodes_from[level].size() <= 1){
                --level;
            }
            int node = nodes_from[level].back();
            int new_parent = nodes_from[level].front() + nodes_from[level + 1].size() / 2;
            p[node] = new_parent;
            nodes_from[level + 1].push_back(node);
            nodes_from[level].pop_back();
            ++level;
            ++sum;
        }
        
        cout << "YES\n";
        for(int i = 2; i <= n; ++i){
            cout << p[i] << " ";
        }
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int t;
    cin >> t;

    for(; t > 0; --t){
        int n, d;
        cin >> n >> d;
        solve(n, d, cout);
    }

    return 0;
}