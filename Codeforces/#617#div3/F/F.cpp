#include <algorithm>
#include <cmath>
#include <map>
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

void bfs(vector <vector<pair<int, int>>>& a, const int& src_node,
         const int& dest_node, vector <pair<int, int>>& prev){
    queue <int> q;

    q.push(src_node);
    prev[src_node] = {src_node, -1};

    bool search = true;
    while(search && !q.empty()){
        int x = q.front();
        q.pop();

        for(unsigned int j = 0; search && j < a[x].size(); ++j){
            int y = a[x][j].first;
            int edge_idx = a[x][j].second;

            if(prev[y].first == 0){
                prev[y] = {x, edge_idx};
                q.push(y);
            }

            if(y == dest_node){
                search = false;
            }
        }
    }
}

void set_zero(vector <pair<int, int>>& v){
    for(unsigned int i = 0; i < v.size(); ++i){
        v[i] = {0, 0};
    }
}

void solve(vector <vector<pair<int, int>>>& a, const int& n,
           vector <tuple<int, int, int>>& info, ostream& cout){

    vector <int> sol(n + 1, 0);
    vector <pair<int, int>> prev(n + 1);

    // Step 1: fill all paths from info
    for(auto t: info){
        int src_node, dest_node, min_v;
        tie(src_node, dest_node, min_v) = t;

        set_zero(prev);

        bfs(a, src_node, dest_node, prev);

        for(int x = dest_node; x != src_node; x = prev[x].first){
            int edge_idx = prev[x].second;
            sol[edge_idx] = max(min_v, sol[edge_idx]);
        }
    }

    // Step 2: test if all conditions from info are satisfied
    bool ok = true;
    for(auto t: info){
        int src_node, dest_node, min_v;
        tie(src_node, dest_node, min_v) = t;

        set_zero(prev);

        bfs(a, src_node, dest_node, prev);

        int path_min = (int)(1e6);
        for(int x = dest_node; x != src_node; x = prev[x].first){
            int edge_idx = prev[x].second;
            path_min = min(path_min, sol[edge_idx]);
        }

        if(path_min != min_v){
            ok = false;
            break;
        }
    }

    if(ok){
        for(int i = 1; i <= n - 1; ++i){
            if(sol[i] == 0){
                sol[i] = (int)(1e6);
            }
            cout << sol[i] << " ";
        }
    }else{
        cout << "-1";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int n;
    cin >> n;

    vector <vector<pair<int, int>>> a(n + 1, vector<pair<int, int>>());
    int x, y;
    for(int i = 1; i <= n - 1; ++i){
        cin >> x >> y;
        a[x].push_back({y, i});
        a[y].push_back({x, i});
    }

    int m;
    cin >> m;

    vector <tuple<int, int, int>> info(m);
    int src_node, dest_node, min_v;
    for(int i = 0; i < m; ++i){
        cin >> src_node >> dest_node >> min_v;
        info[i] = make_tuple(src_node, dest_node, min_v);
    }

    solve(a, n, info, cout);

    return 0;
}