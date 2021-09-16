#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void printGrayCode(int n){
        const int FULL_MASK = (1 << n) - 1;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            for(int bit = n - 1; bit >= 0; --bit){
                int bitVal = 0;
                if((1 << bit) <= mask){
                    int blockIdx = 1 + (mask - (1 << bit)) / (1 << (bit + 1));
                    bitVal = (blockIdx & 1);
                }
                cout << bitVal;
            }
            cout << "\n";
        }
    }
};

int main(){
    int n;
    cin >> n;

    Solution().printGrayCode(n);

    return 0;
}