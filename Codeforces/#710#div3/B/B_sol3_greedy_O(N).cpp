#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    int answer = 1;
    int pos = s.find('*');
    while(pos < N){
        int maxPos = pos;
        for(int i = 1; i <= K && pos + i < N; ++i){
            if(s[pos + i] == '*'){
                maxPos = pos + i;
            }
        }
        if(pos < maxPos){
            answer += 1;
            pos = maxPos;
        }else{
            pos = N;
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