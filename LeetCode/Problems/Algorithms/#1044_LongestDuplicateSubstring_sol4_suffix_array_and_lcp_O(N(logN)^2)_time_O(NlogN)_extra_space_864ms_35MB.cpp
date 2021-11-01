class Solution {
private:
    int computeMaxLCPLen(const string& S, int idx1, int idx2, vector<vector<int>>& c){
        if(S[idx1] != S[idx2]){
            return 0;
        }
        const int N = S.length();
        const int LOG_N = (int)c.size() - 1;
        int maxLCPLen = 0;
        for(int k = LOG_N; k >= 0; --k){
            if(max(idx1, idx2) < N && c[k][idx1] == c[k][idx2]){
                maxLCPLen += (1 << k);
                idx1 += (1 << k);
                idx2 += (1 << k);
            }
        }
        return maxLCPLen;
    }
    
public:
    string longestDupSubstring(string s) {
        const int N = s.length();
        const int LOG_N = ceil(log2(N));
        
        // c[k][i]: equivalence class of s[i .. i + 2^k - 1] in the sorted vector of suffixes of length 2^k
        vector<vector<int>> c(LOG_N + 1, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = s[i] - 'a';
        }
        
        vector<pair<pair<int, int>, int>> temp(N);
        for(int k = 1; k <= LOG_N; ++k){
            int halfLen = (1 << k) / 2;
            for(int i = 0; i < N; ++i){
                int l = c[k - 1][i];
                int r = (i + halfLen < N ? c[k - 1][i + halfLen] : -1);
                temp[i] = {{l, r}, i};
            }
            
            sort(temp.begin(), temp.end());
            
            int classID = 0;
            c[k][temp[0].second] = classID;
            for(int i = 1; i < N; ++i){
                if(temp[i - 1].first != temp[i].first){
                    ++classID;
                }
                c[k][temp[i].second] = classID;
            }
        }
        
        // p[i]: starting index of the ith sorted suffix in string s
        vector<int> p(N);
        for(int i = 0; i < N; ++i){
            p[c[LOG_N][i]] = i;
        }
        
        int startIdx = 0;
        int maxLen = 0;
        for(int i = 0; i + 1 < N; ++i){
            int len = computeMaxLCPLen(s, p[i], p[i + 1], c);
            if(len > maxLen){
                maxLen = len;
                startIdx = p[i];
            }
        }
        
        return s.substr(startIdx, maxLen);
    }
};