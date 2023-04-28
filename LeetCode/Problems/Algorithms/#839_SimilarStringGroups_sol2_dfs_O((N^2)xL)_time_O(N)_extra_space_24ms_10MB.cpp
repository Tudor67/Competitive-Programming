class Solution {
private:
    bool areSimilar(const string& A, const string& B){
        const int L = A.length();
        int mismatches = 0;
        for(int i = 0; i < L && mismatches <= 2; ++i){
            if(A[i] != B[i]){
                mismatches += 1;
            }
        }
        return (mismatches <= 2);
    }

    void dfs(int i, vector<bool>& vis, vector<string>& strs){
        const int N = strs.size();
        vis[i] = true;
        for(int j = 0; j < N; ++j){
            if(!vis[j] && areSimilar(strs[i], strs[j])){
                dfs(j, vis, strs);
            }
        }
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        const int N = strs.size();
        const int L = strs[0].length();

        int groups = 0;
        vector<bool> vis(N, false);
        for(int i = 0; i < N; ++i){
            if(!vis[i]){
                groups += 1;
                dfs(i, vis, strs);
            }
        }

        return groups;
    }
};