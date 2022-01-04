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
    
    int computeMaxValidLCP(vector<int>& lcp, vector<int>& suff, vector<pair<int, int>>& v, const int& PATHS_SIZE){
        int maxValidLCP = 0;
        int distinctPaths = 0;
        vector<int> count(PATHS_SIZE);
        deque<int> dq;
        
        int startIdx = 0;
        while(startIdx < (int)suff.size() && v[suff[startIdx]].second < 0){
            startIdx += 1;
        }
        
        for(int i = startIdx, j = startIdx; j < (int)suff.size(); ++j){
            int pathId = v[suff[j]].second;
            if(count[pathId] == 0){
                distinctPaths += 1;
            }
            count[pathId] += 1;
            
            while(!dq.empty() && lcp[dq.back()] >= lcp[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            
            while(count[v[suff[i]].second] >= 2){
                count[v[suff[i]].second] -= 1;
                i += 1;
            }
            
            while(!dq.empty() && dq.front() <= i){
                dq.pop_front();
            }
            
            if(distinctPaths == PATHS_SIZE && !dq.empty()){
                int validLCP = lcp[dq.front()];
                maxValidLCP = max(maxValidLCP, validLCP);
            }
        }
        
        return maxValidLCP;
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
        
        return computeMaxValidLCP(lcp, suff, v, (int)paths.size());
    }
};