#include <iostream>
using namespace std;

int main(){
    const int N = 1000;
    int sum = 0;
    
    for(int i = 3; i < N; ++i){
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    
    // 233168
    cout << sum;
    
    return 0;
}