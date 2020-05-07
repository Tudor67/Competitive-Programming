#include <iostream>
using namespace std;

int main(){
    int a = 1;
    int b = 1;
    int c = a + b;
    int sum_of_evens = 0;
    
    while(c <= 4e6){
        if(c % 2 == 0){
            sum_of_evens += c;
        }
        a = b;
        b = c;
        c = a + b;
    }
    
    // 4613732
    cout << sum_of_evens;
    
    return 0;
}