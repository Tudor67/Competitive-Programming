#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    long long N, M;
    cin >> N >> M;

    vector<long long> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    vector<long long> q(M);
    for(int i = 0; i < M; ++i){
        cin >> q[i];
    }

    const long long CYCLE_SUM = accumulate(a.begin(), a.end(), 0LL);
    vector<long long> stIdx;
    vector<long long> stVal;
    long long prefSum = 0;
    for(int i = 0; i < N; ++i){
        prefSum += a[i];
        if(prefSum > 0){
            if(stVal.empty() || stVal.back() < prefSum){
                stVal.push_back(prefSum);
                stIdx.push_back(i);
            }
        }
    }

    for(int i = 0; i < M; ++i){
        long long x = q[i];
        long long answer = 0;
        if(stVal.empty() || (CYCLE_SUM <= 0 && stVal.back() < x)){
            answer = -1;
        }else if(x <= stVal.back()){
            int pos = lower_bound(stVal.begin(), stVal.end(), x) - stVal.begin();
            answer = stIdx[pos];
        }else if(stVal.back() < x){
            long long cycles = (x - stVal.back() + CYCLE_SUM - 1) / CYCLE_SUM;
            x -= cycles * CYCLE_SUM;
            answer = cycles * N;
            if(x == 0){
                answer -= 1;
            }else if(x > 0){
                int pos = lower_bound(stVal.begin(), stVal.end(), x) - stVal.begin();
                answer += stIdx[pos];
            }
        }
        cout << answer << " ";
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