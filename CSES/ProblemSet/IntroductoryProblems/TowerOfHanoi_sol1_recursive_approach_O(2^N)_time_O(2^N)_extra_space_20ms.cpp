#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void hanoi(int n, int a, int b, int c, vector<pair<int, int>>& moves){
        if(n > 0){
            hanoi(n - 1, a, c, b, moves);
            moves.emplace_back(a, b);
            hanoi(n - 1, c, b, a, moves);
        }
    }
};

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> moves;
    Solution().hanoi(n, 1, 3, 2, moves);

    cout << moves.size() << "\n";
    for(const pair<int, int>& P: moves){
        cout << P.first << " " << P.second << "\n";
    }

    return 0;
}