#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void generateGrayCode(int n, int& code, vector<int>& grayCode){
        if(n == 0){
            grayCode.push_back(code);
        }else{
            generateGrayCode(n - 1, code, grayCode);
            code ^= (1 << (n - 1));
            generateGrayCode(n - 1, code, grayCode);
        }
    }

public:
    void generateGrayCode(int n, vector<int>& grayCode){
        int code = 0;
        grayCode.clear();
        generateGrayCode(n, code, grayCode);
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