#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void printHanoiMoves(int n, int a, int b, int c){
        if(n > 0){
            printHanoiMoves(n - 1, a, c, b);
            cout << a << " " << b << "\n";
            printHanoiMoves(n - 1, c, b, a);
        }
    }
};

int main(){
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    Solution().printHanoiMoves(n, 1, 3, 2);

    return 0;
}