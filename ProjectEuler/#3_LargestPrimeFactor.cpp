#include <cmath>
#include <iostream>
using namespace std;

int main(){
    long long n = 600851475143;
    long long lim = sqrt(n);
    long long largest_prime = -1;
    
    for(long long x = 2; x <= lim; ++x){
        if(n % x == 0){
            largest_prime = x;
            while(n % x == 0){
                n /= x;
            }
        }
    }
    
    if(n > 1){
        largest_prime = n;
    }
    
    // 6857
    cout << largest_prime;
    
    return 0;
}