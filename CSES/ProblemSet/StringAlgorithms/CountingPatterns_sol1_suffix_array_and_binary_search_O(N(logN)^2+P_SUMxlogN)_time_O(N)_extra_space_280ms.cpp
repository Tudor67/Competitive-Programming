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

    int lowerBound(const string& S, const string& WORD, vector<int>& suff){
        const int N = S.length();
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(S.compare(suff[mid], WORD.length(), WORD, 0, WORD.length()) < 0){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

    int upperBound(const string& S, const string& WORD, vector<int>& suff){
        const int N = S.length();
        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(S.compare(suff[mid], WORD.length(), WORD, 0, WORD.length()) <= 0){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    void countPatterns(const string& S, const vector<string>& P, vector<int>& count){
        const int N = S.length();
        const int K = P.size();

        vector<int> suff;
        computeSuffixArray(S, suff);
        
        count.resize(K);
        for(int i = 0; i < K; ++i){
            int lowerIdx = lowerBound(S, P[i], suff);
            int upperIdx = upperBound(S, P[i], suff);
            count[i] = upperIdx - lowerIdx;
        }
    }
};

int main(){
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<string> p(k);
    for(int i = 0; i < k; ++i){
        cin >> p[i];
    }

    vector<int> count;
    Solution().countPatterns(s, p, count);

    for(int i = 0; i < k; ++i){
        cout << count[i] << "\n";
    }

    return 0;
}