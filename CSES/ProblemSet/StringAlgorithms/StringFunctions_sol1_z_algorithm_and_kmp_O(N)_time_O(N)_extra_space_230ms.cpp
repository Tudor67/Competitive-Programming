#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void computeZArray(const string& S, vector<int>& z){
        const int N = S.length();

        z.assign(N, 0);
        int l = 0;
        int r = 0;
        for(int i = 1; i < N; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < N && S[z[i]] == S[i + z[i]]){
                ++z[i];
            }
            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

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
    void printZP(const string& S){
        const int N = S.length();

        vector<int> z;
        computeZArray(S, z);

        vector<int> p;
        computePrefixFunction(S, p);

        for(int i = 0; i < N; ++i){
            cout << z[i] << " ";
        }

        cout << "\n";

        for(int i = 0; i < N; ++i){
            cout << p[i] << " ";
        }
    }
};

int main(){
    string s;
    cin >> s;

    Solution().printZP(s);

    return 0;
}