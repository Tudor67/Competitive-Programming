#include <bits/stdc++.h>
using namespace std;

int computeMaxPrefLen(const string& S, const string& T){
    const int S_LEN = S.length();
    const int T_LEN = T.length();
    int j = 0;
    for(int i = 0; i < S_LEN && j < T_LEN; ++i){
        if(S[i] == T[j]){
            j += 1;
        }
    }
    return j;
}

int computeMaxSuffLen(const string& S, const string& T){
    const int S_LEN = S.length();
    const int T_LEN = T.length();
    int j = T_LEN - 1;
    for(int i = S_LEN - 1; i >= 0 && j >= 0; --i){
        if(S[i] == T[j]){
            j -= 1;
        }
    }
    return T_LEN - 1 - j;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string T;
    cin >> N >> T;

    const int T_LEN = T.length();

    vector<string> S(N);
    for(int i = 0; i < N; ++i){
        cin >> S[i];
    }

    vector<int> suffCount(T_LEN + 1);
    for(int i = 0; i < N; ++i){
        int len = computeMaxSuffLen(S[i], T);
        suffCount[len] += 1;
    }

    for(int i = T_LEN - 1; i >= 0; --i){
        suffCount[i] += suffCount[i + 1];
    }

    long long res = 0;
    for(int i = 0; i < N; ++i){
        int prefLen = computeMaxPrefLen(S[i], T);
        res += suffCount[T_LEN - prefLen];
    }

    cout << res;

    return 0;
}