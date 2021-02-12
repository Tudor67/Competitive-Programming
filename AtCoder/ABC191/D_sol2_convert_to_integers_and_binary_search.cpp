#include <bits/stdc++.h>
using namespace std;

long long ceil(const long long& X, const long long& MULT_FACTOR){
    return MULT_FACTOR * ((X / MULT_FACTOR) + (X % MULT_FACTOR > 0));
}

long long floor(const long long& X, const long long& MULT_FACTOR){
    return MULT_FACTOR * ((X / MULT_FACTOR) - (X % MULT_FACTOR < 0));
}

long long binarySearch(const long long& DX, const long long& R){
    long long l = 0;
    long long r = R;
    while(l != r){
        long long mid = (l + r + 1) / 2;
        if(mid * mid + DX * DX > R * R){
            r = mid - 1;
        }else{
            l = mid;
        }
    }
    return r;
}

long long readLL(const string& S, long long multFactor){
    long long num = 0;
    bool isAfterDot = false;
    for(int i = 0; i < (int)S.length(); ++i){
        if(isdigit(S[i])){
            num = num * 10 + S[i] - '0';
            if(isAfterDot){
                multFactor /= 10;
            }
        }else if(S[i] == '.'){
            isAfterDot = true;
        }
    }
    num *= multFactor;
    if(S[0] == '-'){
        num = -num;
    }
    return num;
}

int main(){
    string XStr, YStr, RStr;
    cin >> XStr >> YStr >> RStr;

    const long long MULT_FACTOR = 10000;
    long long X = readLL(XStr, MULT_FACTOR);
    long long Y = readLL(YStr, MULT_FACTOR);
    long long R = readLL(RStr, MULT_FACTOR);

    long long answer = 0;
    for(long long x = ceil(X - R, MULT_FACTOR); x <= X + R; x += MULT_FACTOR){
        long long dx = abs(X - x);
        long long dy = binarySearch(dx, R);
        long long y1 = floor(Y + dy, MULT_FACTOR);
        long long y2 = ceil(Y - dy, MULT_FACTOR);
        answer += (y1 - y2 + MULT_FACTOR) / MULT_FACTOR;
    }

    cout << answer;

    return 0;
}