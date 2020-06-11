#include <iostream>
#include <vector>
using namespace std;

int seq_len(long long n, vector<int>& d){
    if(n == 1){
        d[1] = 1;
        return 1;
    }
    
    if(n < d.size() && d[n] != -1){
        return d[n];
    }
    
    int len;
    if(n % 2 == 0){
        len = 1 + seq_len(n / 2, d);
    }else{
        len = 1 + seq_len(3 * n + 1, d);
    }
    
    if(n < d.size()){
        d[n] = len;
    }
    
    return len;
}

int main(){
    const int MAX_N = 1e6;
    vector<int> d(MAX_N, -1);
    
    int max_val = 1;
    int max_len = 1;
    for(long long i = 1; i < MAX_N; ++i){
        int len = seq_len(i, d);
        if(len > max_len){
            max_len = len;
            max_val = i;
        }
    }
    
    // 837799: 525
    cout << max_val << ": " << max_len;
    return 0;
}