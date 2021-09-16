#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void printGrayCode(int n){
        const int FULL_MASK = (1 << n) - 1;
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int code = (mask ^ (mask >> 1));
            for(int bit = n - 1; bit >= 0; --bit){
                cout << ((code >> bit) & 1);
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