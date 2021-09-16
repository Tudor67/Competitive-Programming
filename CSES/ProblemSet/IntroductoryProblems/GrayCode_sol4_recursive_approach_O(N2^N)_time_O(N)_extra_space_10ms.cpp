#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void printGrayCode(int n, string& code){
        if(n == 0){
            cout << code << "\n";
        }else{
            printGrayCode(n - 1, code);
            code[n - 1] = '0' + ((code[n - 1] - '0') ^ 1);
            printGrayCode(n - 1, code);
        }
    }

public:
    void printGrayCode(int n){
        string code(n, '0');
        printGrayCode(n, code);
    }
};

int main(){
    int n;
    cin >> n;

    Solution().printGrayCode(n);

    return 0;
}