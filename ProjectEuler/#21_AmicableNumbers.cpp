#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int MAX_N = (1e4) - 1;
    vector<int> d(MAX_N + 1, 0);
    
    for(int j = 1; j <= MAX_N; ++j){
        for(int i = 2 * j; i <= MAX_N; i += j){
            d[i] += j;
        }
    }
    
    int answer = 0;
    for(int a = 2; a <= MAX_N; ++a){
        int b = d[a];
        if(a != b && d[b] == a){
            answer += a;
        }
    }
    
    // 31626
    cout << answer;
    
    return 0;
}