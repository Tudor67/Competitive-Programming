#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimalRotationIdx(const string& S){
        const int N = S.length();
        int minIdx = 0;
        string minS = S;
        for(int i = 0; i < N; ++i){
            string currentS = S.substr(i) + S.substr(0, i);
            if(currentS < minS){
                minIdx = i;
                minS = currentS;
            }
        }
        return minIdx;
    }
};

int main(){
    string s;
    cin >> s;

    int minIdx = Solution().minimalRotationIdx(s);
    string minS = s.substr(minIdx) + s.substr(0, minIdx);

    cout << minS;

    return 0;
}