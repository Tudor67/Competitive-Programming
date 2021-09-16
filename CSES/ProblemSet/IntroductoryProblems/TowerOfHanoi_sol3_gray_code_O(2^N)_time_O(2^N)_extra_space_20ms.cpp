#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void hanoi(int n, int a, int b, int c, vector<pair<int, int>>& moves){
        const int FULL_MASK = (1 << n) - 1;

        vector<stack<int>> st(4);
        for(int i = n - 1; i >= 0; --i){
            st[a].push(i);
        }

        for(int mask = 1; mask <= FULL_MASK; ++mask){
            int prevGrayCode = (mask - 1) ^ ((mask - 1) >> 1);
            int curGrayCode = mask ^ (mask >> 1);
            int disk = __builtin_ctz((unsigned int)(prevGrayCode ^ curGrayCode));

            int srcSt = -1;
            if(!st[a].empty() && st[a].top() == disk){
                srcSt = a;
            }else if(!st[b].empty() && st[b].top() == disk){
                srcSt = b;
            }else if(!st[c].empty() && st[c].top() == disk){
                srcSt = c;
            }

            int dstSt = -1;
            if(st[a].empty() || disk < st[a].top()){
                dstSt = a;
            }else if(st[b].empty() || disk < st[b].top()){
                dstSt = b;
            }else if(st[c].empty() || disk < st[c].top()){
                dstSt = c;
            }

            if(disk == 0){
                if(n % 2 == 0){
                    if(srcSt == a){
                        dstSt = c;
                    }else if(srcSt == c){
                        dstSt = b;
                    }else{
                        dstSt = a;
                    }
                }else{
                    if(srcSt == a){
                        dstSt = b;
                    }else if(srcSt == b){
                        dstSt = c;
                    }else{
                        dstSt = a;
                    }
                }
            }

            st[srcSt].pop();
            st[dstSt].push(disk);

            moves.emplace_back(srcSt, dstSt);
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