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

template<class T>
class BinaryIndexedTree{
    private:
        vector<T> tree;
        int n;

    public:
        BinaryIndexedTree(const int& n){
            this->n = n;
            tree.resize(n + 1, 0);
        }

        void update(const int& pos, const int& val){
            for(int i = pos; i <= n; i += (i & (-i))){
                tree[i] += val;
            }
        }

        T query(const int& pos){
            T sum = 0;
            for(int i = pos; i >= 1; i -= (i & (-i))){
                sum += tree[i];
            }
            return sum;
        }
};

bool second_less_comp(const pair<int, int>& lhs, const pair<int, int>& rhs){
    return lhs.second < rhs.second;
}
 
int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    // read
    int n;
    cin >> n;

    vector<pair<int, int>> xv(n);
    for(int i = 0; i < n; ++i){
        cin >> xv[i].first;
    }

    for(int i = 0; i < n; ++i){
        cin >> xv[i].second;
    }

    // map v from [-1e8, 1e8] to [1, maximum 2e5]
    sort(xv.begin(), xv.end(), second_less_comp);
    map<int, int> pos;
    int max_pos = 0;
    for(int i = 0; i < n; ++i){
        int v = xv[i].second;
        if(pos.find(v) == pos.end()){
            pos[v] = ++max_pos;
        }
    }
    
    // solve
    BinaryIndexedTree<int> cnt_tree(max_pos);
    BinaryIndexedTree<long long> sum_tree(max_pos);

    sort(xv.begin(), xv.end());

    long long sol = 0;
    for(int i = 0; i < n; ++i){
        int x = xv[i].first;
        int v = xv[i].second;

        long long cnt = cnt_tree.query(pos[v]);
        long long sum = sum_tree.query(pos[v]);
        
        sol += x * cnt - sum;

        cnt_tree.update(pos[v], 1);
        sum_tree.update(pos[v], x);
    }

    cout << sol;

    return 0;
}