#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<long long>& a1, vector<long long>& a2, int maxPoints, int minUnits){
    const int N1 = a1.size();
    const int N2 = a2.size();
    long long maxUnitsSum = 0;
    for(int c1 = 0; c1 <= N1 && c1 <= maxPoints; ++c1){
        long long s = (c1 >= 1 ? a1[c1 - 1] : 0);
        long long remPoints = maxPoints - c1;
        if(remPoints >= 2 && N2 >= 1){
            s += a2[min(N2 - 1LL, remPoints / 2 - 1)];
        }
        maxUnitsSum = max(s, maxUnitsSum);
    }
    return (maxUnitsSum >= minUnits);
}

void solve(){
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &a[i]);
    }

    vector<int> b(N);
    vector<long long> a1;
    vector<long long> a2;
    for(int i = 0; i < N; ++i){
        scanf("%d", &b[i]);
        if(b[i] == 1){
            a1.push_back(a[i]);
        }else{
            a2.push_back(a[i]);
        }
    }

    sort(a1.rbegin(), a1.rend());
    sort(a2.rbegin(), a2.rend());

    for(int i = 1; i < a1.size(); ++i){
        a1[i] += a1[i - 1];
    }

    for(int i = 1; i < a2.size(); ++i){
        a2[i] += a2[i - 1];
    }

    const long long MAX_POSSIBLE_MEMORY = accumulate(a.begin(), a.end(), 0LL);
    const int MAX_POSSIBLE_POINTS = accumulate(b.begin(), b.end(), 0);
    long long answer = -1;
    if(MAX_POSSIBLE_MEMORY >= M){
        long long l = 1;
        long long r = MAX_POSSIBLE_POINTS;
        while(l != r){
            long long mid = (l + r) / 2;
            if(isValid(a1, a2, mid, M)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        answer = r;
    }

    printf("%lld\n", answer);
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        freopen((string(argv[1]) + ".in").c_str(), "r", stdin);
        freopen((string(argv[1]) + ".out").c_str(), "w", stdout);
    #endif
    
    int tests;
    scanf("%d", &tests);
    
    while(tests > 0){
        solve();
        tests -= 1;
    }

    return 0;
}