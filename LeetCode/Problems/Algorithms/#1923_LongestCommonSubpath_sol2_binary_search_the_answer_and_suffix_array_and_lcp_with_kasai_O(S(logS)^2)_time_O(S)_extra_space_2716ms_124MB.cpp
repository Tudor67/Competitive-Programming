class Solution {
private:
    void computeSuffixArray(vector<pair<int, int>>& v, vector<int>& suff){
        const int N = v.size();
        const int LOG_N = 1 + floor(log2(N));
        
        vector<vector<int>> c(2, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = v[i].first;
        }
        
        vector<pair<pair<int, int>, int>> temp(N);
        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i < N; ++i){
                int l = c[(k - 1) % 2][i];
                int r = (i + len / 2 < N ? c[(k - 1) % 2][i + len / 2] : -1);
                temp[i].first = {l, r};
                temp[i].second = i;
            }
            
            sort(temp.begin(), temp.end());
            
            int classID = 0;
            c[k % 2][temp[0].second] = 0;
            for(int i = 1; i < N; ++i){
                if(temp[i - 1].first != temp[i].first){
                    classID += 1;
                }
                c[k % 2][temp[i].second] = classID;
            }
        }
        
        // suff[i]: start position of the ith sorted suffix in vector v[..].first
        suff.assign(N, 0);
        for(int i = 0; i < N; ++i){
            suff[c[LOG_N % 2][i]] = i;
        }
    }
    
    void computeLCPWithKasai(vector<pair<int, int>>& v, vector<int>& suff, vector<int>& lcp){
        const int N = v.size();
        
        // rank is c[LOG_N % 2] from computeSuffixArray
        // rank is inverse of suff
        // rank[i]: the position of suffix v[i..].first in the array of sorted suffixes
        vector<int> rank(N);
        for(int i = 0; i < N; ++i){
            rank[suff[i]] = i;
        }
        
        // lcp[i]: length of the longest common prefix of (i - 1)th and ith sorted suffix
        lcp.assign(N, 0);
        
        int k = 0;
        for(int i = 0; i < N; ++i){
            if(rank[i] == 0){
                k = 0;
                continue;
            }
            int j = suff[rank[i] - 1];
            while(i + k < N && j + k < N && v[i + k].first == v[j + k].first){
                k += 1;
            }
            lcp[rank[i]] = k;
            k = max(0, k - 1);
        }
    }
    
    bool isValid(vector<int>& lcp, vector<int>& suff, vector<pair<int, int>>& v, const int& PATHS_SIZE, const int& THRESHOLD){
        if(THRESHOLD == 0){
            return true;
        }
        vector<bool> vis(PATHS_SIZE, false);
        for(int i = 0, j = 0; j < (int)lcp.size(); ++j){
            if(lcp[j] < THRESHOLD){
                int distinctPaths = 0;
                for(int k = max(0, i - 1); k <= j - 1; ++k){
                    int pathId = v[suff[k]].second;
                    if(pathId >= 0 && !vis[pathId]){
                        vis[pathId] = true;
                        distinctPaths += 1;
                    }
                }
                if(distinctPaths == PATHS_SIZE){
                    return true;
                }
                for(int k = max(0, i - 1); k <= j - 1; ++k){
                    int pathId = v[suff[k]].second;
                    if(pathId >= 0){
                        vis[pathId] = false;
                    }
                }
                i = j + 1;
            }
        }
        return false;
    }
    
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        vector<pair<int, int>> v;
        for(int i = 0; i < (int)paths.size(); ++i){
            for(int j = 0; j < (int)paths[i].size(); ++j){
                v.emplace_back(paths[i][j], i);
            }
            v.emplace_back(-1, -1);
        }
        v.pop_back();
        
        vector<int> suff;
        computeSuffixArray(v, suff);
        
        vector<int> lcp;
        computeLCPWithKasai(v, suff, lcp);
        lcp.push_back(0);
        
        int l = 0;
        int r = *max_element(lcp.begin(), lcp.end());
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(lcp, suff, v, (int)paths.size(), mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};