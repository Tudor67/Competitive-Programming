#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void generateGrayCode(int n, vector<int>& grayCode){
        grayCode.clear();
        grayCode.resize(1 << n, 0);
        for(int step = 0; step < n; ++step){
            for(int i = (1 << step) - 1, j = (1 << step); i >= 0; --i, ++j){
                grayCode[j] = (1 << step) | grayCode[i];
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