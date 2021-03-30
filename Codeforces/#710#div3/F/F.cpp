#include <bits/stdc++.h>
using namespace std;

pair<int, int> getCCParams(const pair<int, int>& P){
    int row = P.first;
    int col = P.second;
    return {(row - col) / 2, (row - col) % 2};
}

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<pair<int, int>> rc(N + 1);
    rc[0] = {1, 1};
    for(int i = 1; i <= N; ++i){
        cin >> rc[i].first;
    }
    for(int i = 1; i <= N; ++i){
        cin >> rc[i].second;
    }

    sort(rc.begin(), rc.end());

    int answer = 0;
    for(int i = 1; i <= N; ++i){
        pair<int, int> P0 = getCCParams(rc[i - 1]);
        pair<int, int> P1 = getCCParams(rc[i]);
        if(P0.first == P1.first){
            if(P0.second == 0 && P1.second == 0){
                answer += (rc[i].first - rc[i - 1].first);
            }
        }else{
            answer += (P1.first - P0.first);
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