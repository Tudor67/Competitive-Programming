#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int N = 10001;
    const int MAX_VAL = 110000;
    vector<bool> is_prime(MAX_VAL + 1, true);
    
    int prime_cnt = 0;
    int nth_prime = -1;
    for(int i = 2; i <= MAX_VAL; ++i){
        if(is_prime[i]){
            ++prime_cnt;
            if(prime_cnt == N){
                nth_prime = i;
                break;
            }
            for(int j = i + i; j <= MAX_VAL; j += i){
                is_prime[j] = false;
            }
        }
    }
    
    // Nth prime: 104743
    cout << nth_prime;
    
    return 0;
}