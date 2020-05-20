#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int MAX_VAL = 2e6;
    vector<bool> is_prime(MAX_VAL + 1, true);
    
    long long sum = 0;
    for(int i = 2; i <= MAX_VAL; ++i){
        if(is_prime[i]){
            sum += i;
            for(int j = i + i; j <= MAX_VAL; j += i){
                is_prime[j] = false;
            }
        }
    }
    
    // 142913828922
    cout << sum;
    return 0;
}