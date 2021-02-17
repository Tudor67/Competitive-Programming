#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, const int& L, const int& R, const vector<int>& A, vector<int>& d){
    if(L > R){
        return;
    }

    int maxPos = L;
    for(int i = L; i <= R; ++i){
        if(A[i] > A[maxPos]){
            maxPos = i;
        }
    }

    d[A[maxPos]] = depth;

    dfs(depth + 1, L, maxPos - 1, A, d);
    dfs(depth + 1, maxPos + 1, R, A, d);
}

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }

    vector<int> d(N + 1, -1);
    dfs(0, 1, N, a, d);

    for(int i = 1; i <= N; ++i){
        cout << d[a[i]] << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}