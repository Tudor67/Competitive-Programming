#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const char CO = 'o';
const char CX = 'x';
const char DOT = '.';

int solve(const string& S, const int K){
    const int N = S.length();

    int res = INF;
    unordered_map<char, int> f;

    for(int i = 0; i < N; ++i){
        f[S[i]] += 1;
        if(i >= K){
            f[S[i - K]] -= 1;
        }

        if(i >= K - 1 && f[CX] == 0){
            res = min(res, f[DOT]);
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ROWS, COLS, K;
    cin >> ROWS >> COLS >> K;

    vector<string> s(ROWS);
    for(int row = 0; row < ROWS; ++row){
        cin >> s[row];
    }

    vector<string> sT(COLS, string(ROWS, '.'));
    for(int row = 0; row < ROWS; ++row){
        for(int col = 0; col < COLS; ++col){
            sT[col][row] = s[row][col];
        }
    }

    int res = INF;
    for(int row = 0; row < ROWS; ++row){
        res = min(res, solve(s[row], K));
    }

    for(int col = 0; col < COLS; ++col){
        res = min(res, solve(sT[col], K));
    }

    if(res == INF){
        res = -1;
    }

    cout << res;

    return 0;
}