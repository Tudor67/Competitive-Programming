#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string P;
    cin >> P;

    sort(P.begin(), P.end());

    vector<int> targetCount(10);
    vector<int> count(10);
    long long maxNum = 0;
    long long p10 = 1;
    for(char c: P){
        targetCount[c - '0'] += 1;
        maxNum += p10 * (c - '0');
        p10 *= 10;
    }

    int res = 0;
    for(long long i = 0; i * i <= maxNum; ++i){
        long long x = i * i;

        fill(count.begin(), count.end(), 0);

        while(x > 0){
            count[x % 10] += 1;
            x /= 10;
        }

        bool isValid = (count[0] <= targetCount[0]);
        for(int digit = 1; isValid && digit <= 9; ++digit){
            if(count[digit] != targetCount[digit]){
                isValid = false;
            }
        }

        if(isValid){
            res += 1;
        }
    }

    cout << res;

    return 0;
}