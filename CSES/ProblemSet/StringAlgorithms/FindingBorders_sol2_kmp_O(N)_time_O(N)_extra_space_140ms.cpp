#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void computePrefixFunction(const string& S, vector<int>& p){
        const int N = S.length();

        p.assign(N, 0);
        for(int i = 1; i < N; ++i){
            int k = p[i - 1];
            while(k > 0 && S[k] != S[i]){
                k = p[k - 1];
            }
            if(S[k] == S[i]){
                ++k;
            }
            p[i] = k;
        }
    }

public:
    void computeBorderLengths(const string& S, vector<int>& borderLengths){
        const int N = S.length();

        vector<int> p;
        computePrefixFunction(S, p);

        borderLengths.clear();
        for(int k = p[N - 1]; k > 0; k = p[k - 1]){
            borderLengths.push_back(k);
        }
        reverse(borderLengths.begin(), borderLengths.end());
    }
};

int main(){
    string s;
    cin >> s;

    vector<int> borderLengths;
    Solution().computeBorderLengths(s, borderLengths);

    for(int borderLength: borderLengths){
        cout << borderLength << " ";
    }

    return 0;
}