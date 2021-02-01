#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    vector<int> b(N);
    vector<long long> memory[3];
    for(int i = 0; i < N; ++i){
        cin >> b[i];
        memory[b[i]].push_back(a[i]);
    }

    sort(memory[1].rbegin(), memory[1].rend());
    sort(memory[2].rbegin(), memory[2].rend());

    const long long MAX_POSSIBLE_MEMORY1 = accumulate(memory[1].begin(), memory[1].end(), 0LL);
    const long long MAX_POSSIBLE_MEMORY2 = accumulate(memory[2].begin(), memory[2].end(), 0LL);
    const long long MAX_POSSIBLE_POINTS = accumulate(b.begin(), b.end(), 0);
    const int N1 = memory[1].size();
    const int N2 = memory[2].size();

    long long answer = -1;
    if(MAX_POSSIBLE_MEMORY1 + MAX_POSSIBLE_MEMORY2 >= M){
        answer = MAX_POSSIBLE_POINTS;
        long long memoryPrefSum1 = MAX_POSSIBLE_MEMORY1;
        long long memoryPrefSum2 = 0;
        for(int p1 = N1, p2 = 0; p1 >= 0; --p1){
            memoryPrefSum1 -= (p1 == N1 ? 0 : memory[1][p1]);
            while(p2 < N2 && memoryPrefSum1 + memoryPrefSum2 < M){
                memoryPrefSum2 += memory[2][p2];
                p2 += 1;
            }
            long long curMemory = memoryPrefSum1 + memoryPrefSum2;
            long long curPoints = p1 + 2 * p2;
            if(curMemory >= M){
                answer = min(curPoints, answer);
            }else{
                break;
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