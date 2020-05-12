#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void update(const vector<int>& primes, vector<int>& powers, int num){
    for(int i = 0; i < primes.size() && primes[i] <= num; ++i){
        int cnt = 0;
        while(num % primes[i] == 0){
            num /= primes[i];
            ++cnt;
        }
        powers[i] = max(cnt, powers[i]);
    }
}

int get_num(const vector<int>& primes, const vector<int>& powers){
    int num = 1;
    for(int i = 0; i < primes.size(); ++i){
        num *= pow(primes[i], powers[i]);
    }
    return num;
}

int main(){
    const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    vector<int> powers(primes.size(), 0);
    
    for(int num = 2; num <= 20; ++num){
        update(primes, powers, num);
    }
    
    // 232792560
    cout << get_num(primes, powers);
    
    return 0;
}