#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void computeSuffixArray(const string& S, vector<int>& suff){
        const int N = S.length();
        const int LOG_N = 1 + floor(log2(N));

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

        suff.resize(N);
        for(int i = 0; i < N; ++i){
            suff[c[LOG_N % 2][i]] = i;
        }
    }

    void computeLCPWithKasai(const string& S, vector<int>& suff, vector<int>& lcp){
        const int N = S.length();

        vector<int> rank(N);
        for(int i = 0; i < N; ++i){
            rank[suff[i]] = i;
        }

        lcp.resize(N);
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
    }

public:
    string kthSubstring(const string& S, long long k){
        const int N = S.length();

        // suffix array
        vector<int> suff;
        computeSuffixArray(S, suff);

        // compute lcp using kasai's algorithm
        vector<int> lcp;
        computeLCPWithKasai(S, suff, lcp);

        int startPos = 0;
        int len = 0;
        for(int i = 0; i < N; ++i){
            long long count = N - (suff[i] + lcp[i]);
            if(count < k){
                k -= count;
            }else{
                startPos = suff[i];
                len = lcp[i] + k;
                break;
            }
        }

        return S.substr(startPos, len);
    }
};

int main(){
    string s;
    cin >> s;

    long long k;
    cin >> k;

    cout << Solution().kthSubstring(s, k);

    return 0;
}