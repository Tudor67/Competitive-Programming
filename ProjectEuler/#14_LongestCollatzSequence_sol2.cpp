#include <iostream>
#include <vector>
using namespace std;

int seq_len(long long n){
    int len = 1;
    while(n != 1){
        if(n % 2 == 0){
            n /= 2;
        }else{
            n = 3 * n + 1;
        }
        ++len;
    }
    return len;
}

int main(){
    const int MAX_N = 1e6;
    int max_val = 1;
    int max_len = 1;
    for(long long i = 1; i < MAX_N; ++i){
        int len = seq_len(i);
        if(len > max_len){
            max_len = len;
            max_val = i;
        }
    }
    
    // 837799: 525
    cout << max_val << ": " << max_len;
    return 0;
}