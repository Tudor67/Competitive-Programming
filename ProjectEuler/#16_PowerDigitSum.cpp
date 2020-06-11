#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void multiply_with_2(vector<int>& p){
    int carry = 0;
    for(int i = 0; i < p.size(); ++i){
        int s = carry + 2 * p[i];
        p[i] = s % 10;
        carry = s / 10;
    }
    if(carry > 0){
        p.push_back(carry);
    }
}

int main(){
    const int N = 1000;
    vector<int> p = {1};
    for(int i = 1; i <= N; ++i){
        multiply_with_2(p);
    }
    
    // 1366
    cout << accumulate(p.begin(), p.end(), 0);
    
    return 0;
}