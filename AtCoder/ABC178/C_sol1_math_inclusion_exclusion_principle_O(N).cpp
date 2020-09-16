#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long MODULO = (1e9) + 7;
    int N;
    cin >> N;

    long long zero_configs = 0;
    long long nine_configs = 0;
    long long pow8 = 1;
    long long pow10 = 1;
    for(int i = 1; i <= N; ++i){
        zero_configs = (9 * zero_configs + pow10) % MODULO;
        nine_configs = (9 * nine_configs + pow10) % MODULO;
        pow8 = (8 * pow8) % MODULO;
        pow10 = (10 * pow10) % MODULO;
    }

    long long answer = (zero_configs + nine_configs + pow8 - pow10 + MODULO) % MODULO; 
    cout << answer;

    return 0;
}