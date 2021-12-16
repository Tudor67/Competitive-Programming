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
            if(S.compare(suff[mid], WORD.length(), WORD) < 0){
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
            if(S.compare(suff[mid], WORD.length(), WORD) <= 0){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    string kthSubstring(const string& S, long long k){
        const int N = S.length();

        // suffix array
        vector<int> suff;
        computeSuffixArray(S, suff);

        // substringsPrefCount[i]: how many substrings can be formed from sorted suffixes[0 .. i]
        vector<long long> substringsPrefCount(N);
        substringsPrefCount[0] = N - suff[0];
        for(int i = 1; i < N; ++i){
            substringsPrefCount[i] = substringsPrefCount[i - 1] + (N - suff[i]);
        }

        // create step by step the prefix of the kth substring
        string prefix = "a";
        while(k > 0){
            long long lowerIdx = lowerBound(S, prefix, suff);
            long long upperIdx = upperBound(S, prefix, suff);
            
            if(lowerIdx == upperIdx){
                prefix.back() += 1;
            }else{
                long long fixedPrefixCount = upperIdx - lowerIdx;
                long long startWithPrefixCount = substringsPrefCount[upperIdx - 1];
                if(lowerIdx >= 1){
                    startWithPrefixCount -= substringsPrefCount[lowerIdx - 1];
                }
                startWithPrefixCount -= fixedPrefixCount * ((int)prefix.length() - 1);
                if(k <= startWithPrefixCount){
                    // extend the current prefix
                    k -= fixedPrefixCount;
                    if(k > 0){
                        prefix += "a";
                    }
                }else{
                    // next prefix
                    k -= startWithPrefixCount;
                    prefix.back() += 1;
                }
            }
        }
        
        return prefix;
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