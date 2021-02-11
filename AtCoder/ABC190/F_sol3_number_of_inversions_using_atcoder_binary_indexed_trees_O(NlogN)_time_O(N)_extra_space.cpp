#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
        a[i] += 1;
    }

    long long inversions = 0;
    fenwick_tree<int> tree(N + 1);
    for(int i = 1; i <= N; ++i){
        if(a[i] + 1 <= N){
            inversions += tree.sum(a[i] + 1, N + 1);
        }
        tree.add(a[i], 1);
    }

    cout << inversions << "\n";
    for(int i = 1; i <= N - 1; ++i){
        inversions -= (a[i] - 1);
        inversions += (N - a[i]);
        cout << inversions << "\n";
    }

    return 0;
}