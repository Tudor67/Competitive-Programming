#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long double r;
    cin >> r;

    long long N;
    cin >> N;

    long long a = 0;
    long long b = 1;
    long long c = 1;
    long long d = 0;
    while(max(a + c, b + d) <= N){
        long long x = a + c;
        long long y = b + d;
        long double diff = x - r * y;
        if(diff == 0){
            a = x;
            b = y;
            c = x;
            d = y;
            break;
        }else if(diff < 0){
            a = x;
            b = y;
        }else if(diff > 0){
            c = x;
            d = y;
        }
    }

    if(abs(r - (long double)a / (long double)b) <=
       abs(r - (long double)c / (long double)d)){
        cout << a << " " << b;
    }else{
        cout << c << " " << d;
    }

    return 0;
}