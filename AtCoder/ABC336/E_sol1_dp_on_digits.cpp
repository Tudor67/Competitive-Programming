#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 15;
const int MAX_SUM = 9 * MAX_LEN;
const int MAX_REM = MAX_SUM - 1;

long long memo[MAX_LEN + 1][MAX_SUM + 1][MAX_REM + 1];
long long p10[MAX_LEN + 1];

void precomputePowsOf10(const int MAX_LEN){
    p10[0] = 1;
    for(int i = 1; i <= MAX_LEN; ++i){
        p10[i] = p10[i - 1] * 10;
    }
}

void resetMemo(const int MAX_LEN, const int MAX_SUM, const int MAX_REM){
    for(int len = 0; len <= MAX_LEN; ++len){
        for(int sum = 0; sum <= MAX_SUM; ++sum){
            for(int rem = 0; rem <= MAX_REM; ++rem){
                memo[len][sum][rem] = -1;
            }
        }
    }
}

long long f(int len, int sum, int rem, const int TARGET_SUM){
    if(len < 0 || sum < 0){
        return 0;
    }

    if(len == 0){
        return (sum == 0 && rem == 0);
    }

    if(memo[len][sum][rem] != -1){
        return memo[len][sum][rem];
    }

    long long res = 0;
    for(long long digit = 0; digit <= 9; ++digit){
        res += f(len - 1, sum - digit,
                 (rem - digit * p10[len - 1] % TARGET_SUM + TARGET_SUM) % TARGET_SUM,
                 TARGET_SUM);
    }

    memo[len][sum][rem] = res;
    return res;
}

long long countGoodNumbers(long long maxNum, int targetDigitsSum){
    string maxNumStr = to_string(maxNum);
    int maxNumStrLen = maxNumStr.length();

    precomputePowsOf10(maxNumStrLen);
    resetMemo(maxNumStrLen, targetDigitsSum, targetDigitsSum);

    long long res = 0;
    long long prefRem = 0;
    long long prefDigitsSum = 0;

    for(int i = 0; i < maxNumStrLen; ++i){
        int maxValidDigit = maxNumStr[i] - '0' - (i + 1 == maxNumStrLen ? 0 : 1);
        for(int digit = 0; digit <= maxValidDigit; ++digit){
            int newPrefRem = (prefRem + digit * p10[maxNumStrLen - 1 - i]) % targetDigitsSum;
            int newPrefDigitsSum = prefDigitsSum + digit;
            res += f(maxNumStrLen - 1 - i,
                     targetDigitsSum - newPrefDigitsSum,
                     (targetDigitsSum - newPrefRem) % targetDigitsSum,
                     targetDigitsSum);
        }

        prefRem = (prefRem + (maxNumStr[i] - '0') * p10[maxNumStrLen - 1 - i]) % targetDigitsSum;
        prefDigitsSum += maxNumStr[i] - '0';

        if(prefDigitsSum > targetDigitsSum){
            return res;
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long maxNum;
    cin >> maxNum;
    
    long long res = 0;
    long long maxDigitsSum = min(maxNum, 9 * (long long)to_string(maxNum).length());
    for(int digitsSum = 1; digitsSum <= maxDigitsSum; ++digitsSum){
        res += countGoodNumbers(maxNum, digitsSum);
    }

    cout << res;

    return 0;
}