#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

void insert(int pos, vector<int>& a, int n, long long& answer){
    if(pos >= 1 && pos <= n){
        if(a[pos - 1] < a[pos] && a[pos] > a[pos + 1]) answer += a[pos];
        if(a[pos - 1] > a[pos] && a[pos] < a[pos + 1]) answer -= a[pos];
    }
}

void erase(int pos, vector<int>& a, int n, long long& answer){
    if(pos >= 1 && pos <= n){
        if(a[pos - 1] < a[pos] && a[pos] > a[pos + 1]) answer -= a[pos];
        if(a[pos - 1] > a[pos] && a[pos] < a[pos + 1]) answer += a[pos];
    }
}

void solve(){
    int n, q;
    scanf("%d %d\n", &n, &q);

    vector<int> a(n + 2);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }

    a[0] = -1;
    a[n + 1] = -1;

    long long answer = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i - 1] < a[i] && a[i] > a[i + 1]) answer += a[i];
        if(a[i - 1] > a[i] && a[i] < a[i + 1]) answer -= a[i];
    }

    printf("%lld\n", answer);

    for(; q > 0; --q){
        int l, r;
        scanf("%d %d", &l, &r);

        // erase
        erase(l - 1, a, n, answer);
        erase(l, a, n, answer);
        erase(l + 1, a, n, answer);
        if(l != r){
            if(r - 1 != l && r - 1 != l + 1) erase(r - 1, a, n, answer);
            if(r != l + 1) erase(r, a, n, answer);
            erase(r + 1, a, n, answer);
        }

        // swap
        swap(a[l], a[r]);

        // insert
        insert(l - 1, a, n, answer);
        insert(l, a, n, answer);
        insert(l + 1, a, n, answer);
        if(l != r){
            if(r - 1 != l && r - 1 != l + 1) insert(r - 1, a, n, answer);
            if(r != l + 1) insert(r, a, n, answer);
            insert(r + 1, a, n, answer);
        }

        printf("%lld\n", answer);
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        freopen((string(argv[1]) + ".in").c_str(), "r", stdin);
        freopen((string(argv[1]) + ".out").c_str(), "w", stdout);
    #endif
    
    int t;
    scanf("%d\n", &t);

    for(; t > 0; --t){
        solve();
    }

    return 0;
}