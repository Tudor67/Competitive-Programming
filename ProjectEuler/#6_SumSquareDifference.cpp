#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int n = 100;
    int s1 = (n * (n + 1)) / 2;
    int s2 = (n * (n + 1) * (2 * n + 1)) / 6;
    int answer = s1 * s1 - s2;
    
    // 25164150
    cout << answer;
    
    return 0;
}