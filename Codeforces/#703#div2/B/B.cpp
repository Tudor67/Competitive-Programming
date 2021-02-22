#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);
    for(int i = 0; i < N; ++i){
        cin >> x[i] >> y[i];
    }

    long long answer = 1;
    if(N % 2 == 0){
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        answer = (x[N / 2] - x[N / 2 - 1] + 1LL) * (y[N / 2] - y[N / 2 - 1] + 1LL);
    }
    
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