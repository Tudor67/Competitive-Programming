#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<long long> memoryPrefSum[3], const long long& MAX_POINTS, const long long& MIN_MEMORY){
    const long long N1 = memoryPrefSum[1].size();
    const long long N2 = memoryPrefSum[2].size();
    long long maxReleasedMemory = 0;
    for(int c2 = 0; c2 <= N2 && 2 * c2 <= MAX_POINTS; ++c2){
        long long releasedMemory = (c2 == 0 ? 0 : memoryPrefSum[2][c2 - 1]);
        long long remainingPoints = MAX_POINTS - 2 * c2;
        if(N1 >= 1 && remainingPoints >= 1){
            releasedMemory += memoryPrefSum[1][min(N1, remainingPoints) - 1];
        }
        maxReleasedMemory = max(releasedMemory, maxReleasedMemory);
    }
    return (maxReleasedMemory >= MIN_MEMORY);
}

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

    const int N1 = memory[1].size();
    const int N2 = memory[2].size();
    
    vector<long long> memoryPrefSum[3];
    memoryPrefSum[1].resize(N1);
    memoryPrefSum[2].resize(N2);
    partial_sum(memory[1].begin(), memory[1].end(), memoryPrefSum[1].begin());
    partial_sum(memory[2].begin(), memory[2].end(), memoryPrefSum[2].begin());

    const long long MAX_POSSIBLE_MEMORY = accumulate(memory[1].begin(), memory[1].end(), 0LL) +
                                          accumulate(memory[2].begin(), memory[2].end(), 0LL);
    const long long MAX_POSSIBLE_POINTS = accumulate(b.begin(), b.end(), 0);
    
    long long answer = -1;
    if(MAX_POSSIBLE_MEMORY >= M){
        long long l = 1;
        long long r = MAX_POSSIBLE_POINTS;
        while(l != r){
            long long mid = (l + r) / 2;
            if(isValid(memoryPrefSum, mid, M)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        answer = r;
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