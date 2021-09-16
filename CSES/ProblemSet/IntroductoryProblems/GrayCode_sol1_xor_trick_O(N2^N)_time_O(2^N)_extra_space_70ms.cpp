#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void generateGrayCode(int n, vector<int>& grayCode){
        const int FULL_MASK = (1 << n) - 1;
        grayCode.resize(FULL_MASK + 1);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            grayCode[mask] = (mask ^ (mask >> 1));
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