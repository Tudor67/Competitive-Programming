#include <iostream>
using namespace std;

int main(){
    const int N = 1000;
    int abc = 0;
    for(int a = 1; a < N; ++a){
        for(int b = a + 1; b < N; ++b){
            int c = 1000 - (a + b);
            if(b < c){
                if(a * a + b * b == c * c){
                    abc = a * b * c;
                }
            }
        }
    }
    
    // 31875000
    cout << abc;
    
    return 0;
}