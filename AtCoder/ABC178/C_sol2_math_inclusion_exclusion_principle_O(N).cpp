#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long MODULO = (1e9) + 7;
    int N;
    cin >> N;

    long long pow8 = 1;
    long long pow9 = 1;
    long long pow10 = 1;
    for(int i = 1; i <= N; ++i){
        pow8 = (8 * pow8) % MODULO;
        pow9 = (9 * pow9) % MODULO;
        pow10 = (10 * pow10) % MODULO;
    }

    long long answer = ((pow10 - 2 * pow9 + pow8) % MODULO + MODULO) % MODULO; 
    cout << answer;

    return 0;
}