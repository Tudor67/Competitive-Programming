#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimalRotationIdx(const string& S){
        const int N = S.length();

        int startIdx = 0;
        int i = 0;
        int j = 1;
        while(j < 2 * N){
            char ci = (i < N ? S[i] : S[i - N]);
            char cj = (j < N ? S[j] : S[j - N]);
            if(ci == cj){
                i += 1;
                j += 1;
            }else if(ci < cj){
                i = startIdx;
                j += 1;
            }else{
                startIdx += (j - i);
                i = startIdx;
                j += 1;
            }
        }
        
        return startIdx % N;
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