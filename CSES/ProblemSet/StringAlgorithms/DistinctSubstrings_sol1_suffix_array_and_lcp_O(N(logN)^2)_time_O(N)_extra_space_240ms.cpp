#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long countDistinctSubstrings(const string& S){
        const int N = S.length();
        const int LOG_N = 1 + floor(log2(N));

        // suffix array
        vector<vector<int>> c(2, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = S[i] - 'a';
        }

        vector<pair<pair<int, int>, int>> v(N);
        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i < N; ++i){
                int l = c[(k - 1) % 2][i];
                int r = (i + len / 2 < N ? c[(k - 1) % 2][i + len / 2] : -1);
                v[i].first = {l, r};
                v[i].second = i;
            }

            sort(v.begin(), v.end());

            int classID = 0;
            for(int i = 0; i < N; ++i){
                if(i > 0 && v[i - 1].first != v[i].first){
                    ++classID;
                }
                c[k % 2][v[i].second] = classID;
            }
        }

        vector<int> suff(N);
        for(int i = 0; i < N; ++i){
            suff[c[LOG_N % 2][i]] = i;
        }

        vector<int>& rank = c[LOG_N % 2];

        // lcp with kasai's algorithm
        vector<int> lcp(N);
        int k = 0;
        for(int i = 0; i < N; ++i){
            if(rank[i] == 0){
                k = 0;
            }else{
                int j = suff[rank[i] - 1];
                while(i + k < N && j + k < N && S[i + k] == S[j + k]){
                    ++k;
                }
                lcp[rank[i]] = k;
                k = max(0, k - 1);
            }
        }

        long long totalSubstrings = N * (N + 1LL) / 2;
        long long duplicateSubstrings = accumulate(lcp.begin(), lcp.end(), 0LL);

        return totalSubstrings - duplicateSubstrings;
    }
};

int main(){
    string s;
    cin >> s;

    cout << Solution().countDistinctSubstrings(s);

    return 0;
}