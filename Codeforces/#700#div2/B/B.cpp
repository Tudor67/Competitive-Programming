#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    long long A, B, N;
    cin >> A >> B >> N;

    vector<long long> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    vector<long long> b(N);
    for(int i = 0; i < N; ++i){
        cin >> b[i];
    }

    B += *max_element(a.begin(), a.end());
    for(int i = 0; i < N; ++i){
        long long k = (b[i] / A) + (b[i] % A > 0);
        B -= k * a[i];
        if(B <= 0){
            break;
        }
    }

    if(B >= 1){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
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