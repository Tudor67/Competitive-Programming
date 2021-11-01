class Solution {
private:
    void computeLCP(const string& S, vector<int>& p, vector<int>& lcp){
        const int N = S.length();
        
        vector<int> rank(N);
        for(int i = 0; i < N; ++i){
            rank[p[i]] = i;
        }
        
        int k = 0;
        lcp.resize(N - 1);
        for(int i = 0; i < N; ++i){
            if(rank[i] == N - 1){
                k = 0;
            }else{
                int j = p[rank[i] + 1];
                while(max(i, j) + k < N && S[i + k] == S[j + k]){
                    ++k;
                }
                lcp[rank[i]] = k;
                k = max(0, k - 1);
            }
        }
    }
    
public:
    string longestDupSubstring(string s) {
        const int N = s.length();
        const int LOG_N = ceil(log2(N));
        
        // at step k
        // c[i]: equivalence class of s[i .. i + 2^k - 1] in the sorted vector of suffixes of length 2^k
        vector<int> c(N);
        for(int i = 0; i < N; ++i){
            c[i] = s[i] - 'a';
        }
        
        vector<pair<pair<int, int>, int>> temp(N);
        for(int k = 1; k <= LOG_N; ++k){
            int halfLen = (1 << k) / 2;
            for(int i = 0; i < N; ++i){
                int l = c[i];
                int r = (i + halfLen < N ? c[i + halfLen] : -1);
                temp[i] = {{l, r}, i};
            }
            
            sort(temp.begin(), temp.end());
            
            int classID = 0;
            c[temp[0].second] = classID;
            for(int i = 1; i < N; ++i){
                if(temp[i - 1].first != temp[i].first){
                    ++classID;
                }
                c[temp[i].second] = classID;
            }
        }
        
        // p[i]: starting index of the ith sorted suffix in string s
        vector<int> p(N);
        for(int i = 0; i < N; ++i){
            p[c[i]] = i;
        }
        
        vector<int> lcp;
        computeLCP(s, p, lcp);
        
        int idx = max_element(lcp.begin(), lcp.end()) - lcp.begin();
        int startIdx = p[idx];
        int maxLen = lcp[idx];
        
        return s.substr(startIdx, maxLen);
    }
};