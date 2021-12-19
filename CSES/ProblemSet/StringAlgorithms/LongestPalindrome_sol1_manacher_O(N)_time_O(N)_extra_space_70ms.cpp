#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string getLongestPalindrome(const string& S){
        const int N = S.length();
        const int L = 2 * N + 1;
        
        string ss(L, '.');
        for(int i = 0; i < N; ++i){
            ss[2 * i + 1] = S[i];
        }

        vector<int> r(L);
        int a = 0;
        int b = 0;
        for(int i = 1; i < L; ++i){
            if(i <= b){
                r[i] = min(r[a + (b - i)], b - i);
            }
            while(0 <= i - r[i] - 1 && i + r[i] + 1 < L &&
                  ss[i - r[i] - 1] == ss[i + r[i] + 1]){
                ++r[i];
            }
            if(i + r[i] > b){
                a = i - r[i];
                b = i + r[i];
            }
        }

        int maxIdx = max_element(r.begin(), r.end()) - r.begin();
        int len = r[maxIdx];
        int startPos = (maxIdx - len) / 2;

        return S.substr(startPos, len);
    }
};

int main(){
    string s;
    cin >> s;

    cout << Solution().getLongestPalindrome(s);

    return 0;
}