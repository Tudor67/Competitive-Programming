#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int a){
    int s = 0;
    while(a > 0){
        s += a % 10;
        a /= 10;
    }
    return s;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << max(sumOfDigits(a), sumOfDigits(b));
    return 0;
}