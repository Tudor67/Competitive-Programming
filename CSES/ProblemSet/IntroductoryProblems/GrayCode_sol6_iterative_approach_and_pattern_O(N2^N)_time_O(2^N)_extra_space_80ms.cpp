#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void generateGrayCode(int n, vector<int>& grayCode){
        const int FULL_MASK = (1 << n) - 1;
        grayCode.clear();
        grayCode.resize(FULL_MASK + 1, 0);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < n; ++bit){
                if((1 << bit) <= mask){
                    int blockIdx = 1 + (mask - (1 << bit)) / (1 << (bit + 1));
                    if(blockIdx & 1){
                        grayCode[mask] |= (1 << bit);
                    }
                }
            }
        }
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> grayCode;
    Solution().generateGrayCode(n, grayCode);
    
    for(int code: grayCode){
        for(int bit = n - 1; bit >= 0; --bit){
            cout << ((code >> bit) & 1);
        }
        cout << "\n";
    }

    return 0;
}