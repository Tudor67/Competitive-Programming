#include <bits/stdc++.h>
using namespace std;

bool isValid(const string& X, const long long& BASE, const long long& M){
    long long num = 0;
    for(long long i = 0; i < (int)X.length(); ++i){
        if(num > (M - (X[i] - '0')) / BASE){
            return false;
        }
        num = BASE * num + (X[i] - '0');
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string X;
    long long M;
    cin >> X >> M;

    const long long MIN_BASE = *max_element(X.begin(), X.end()) - '0' + 1;
    const long long MAX_BASE = max(MIN_BASE, M);

    long long answer = 0;
    if(X.length() == 1){
        answer = ((X[0] - '0') <= M);
    }else{
        long long l = MIN_BASE;
        long long r = MAX_BASE;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(isValid(X, mid, M)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        if(MIN_BASE == r){
            answer = isValid(X, MIN_BASE, M);
        }else{
            answer = r - MIN_BASE + 1;
        }
    }

    cout << answer;

    return 0;
}