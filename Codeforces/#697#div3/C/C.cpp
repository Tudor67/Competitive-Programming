#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int A_MAX, B_MAX, K;
    cin >> A_MAX >> B_MAX >> K;

    vector<int> a(K);
    vector<int> aCount(A_MAX + 1);
    for(int i = 0; i < K; ++i){
        cin >> a[i];
        aCount[a[i]] += 1;
    }

    vector<int> b(K);
    vector<int> bCount(B_MAX + 1);
    for(int i = 0; i < K; ++i){
        cin >> b[i];
        bCount[b[i]] += 1;
    }

    long long answer = 0;
    for(int i = 0; i < K; ++i){
        answer += K - (aCount[a[i]] + bCount[b[i]]) + 1;
    }
    answer /= 2;

    cout << answer << "\n";
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