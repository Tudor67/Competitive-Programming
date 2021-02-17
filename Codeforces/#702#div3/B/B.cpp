#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> c(3, 0);
    for(int i = 0; i < n; ++i){
        c[a[i] % 3] += 1;
    }

    const int EXPECTED = n / 3;
    int answer = 0;
    while(!(c[0] == c[1] && c[1] == c[2])){
        for(int i = 0; i <= 2; ++i){
            if(c[i] > EXPECTED){
                int d = c[i] - EXPECTED;
                answer += d;
                c[(i + 1) % 3] += d;
                c[i] = EXPECTED;
            }
        }
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