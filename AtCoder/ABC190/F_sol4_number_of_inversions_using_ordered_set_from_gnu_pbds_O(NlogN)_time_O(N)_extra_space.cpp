#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

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
    ordered_set ordSet;
    for(int i = N; i >= 1; --i){
        inversions += ordSet.order_of_key(a[i]);
        ordSet.insert(a[i]);
    }

    cout << inversions << "\n";
    for(int i = 1; i <= N - 1; ++i){
        inversions -= (a[i] - 1);
        inversions += (N - a[i]);
        cout << inversions << "\n";
    }

    return 0;
}