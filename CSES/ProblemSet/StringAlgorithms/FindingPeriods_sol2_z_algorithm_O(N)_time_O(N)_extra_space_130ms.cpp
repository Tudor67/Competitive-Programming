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

public:
    void findPeriodLengths(const string& S, vector<int>& periodLengths){
        const int N = S.length();

        vector<int> z;
        computeZArray(S, z);

        periodLengths.clear();
        for(int i = 1; i < N; ++i){
            if(i + z[i] == N){
                periodLengths.push_back(i);
            }
        }
        periodLengths.push_back(N);
    }
};

int main(){
    string s;
    cin >> s;

    vector<int> periodLengths;
    Solution().findPeriodLengths(s, periodLengths);

    for(int periodLength: periodLengths){
        cout << periodLength << " ";
    }

    return 0;
}