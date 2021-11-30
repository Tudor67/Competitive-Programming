class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        const int A = accounts.size();
        
        // Step 1: DSU and (email -> groupIdx) map
        DSU dsu(A);
        unordered_map<string, int> emailToGroupIdx;
        for(int i = 0; i < A; ++i){
            for(int j = 1; j < (int)accounts[i].size(); ++j){
                const string& EMAIL = accounts[i][j];
                if(emailToGroupIdx.count(EMAIL)){
                    dsu.join(emailToGroupIdx[EMAIL], i);
                }else{
                    emailToGroupIdx[EMAIL] = i;
                }
            }
        }
        
        // Step 2: DSU and (groupIdx -> emails list) map
        unordered_map<int, vector<string>> groupIdxToEmails;
        for(const pair<string, int>& P: emailToGroupIdx){
            const string& EMAIL = P.first;
            const int& OLD_GROUP_IDX = P.second;
            const int GROUP_IDX = dsu.find(OLD_GROUP_IDX);
            groupIdxToEmails[GROUP_IDX].push_back(EMAIL);
        }
        
        // Step 3: answer with vectors of form {accountName, sorted list of emails}
        vector<vector<string>> answer;
        for(const pair<int, vector<string>>& P: groupIdxToEmails){
            const int& GROUP_IDX = P.first;
            const string& ACCOUNT_NAME = accounts[GROUP_IDX][0];
            const vector<string>& ACCOUNT_EMAILS = P.second;
            answer.push_back({ACCOUNT_NAME});
            for(const string& EMAIL: ACCOUNT_EMAILS){
                answer.back().push_back(EMAIL);
            }
            sort(answer.back().begin() + 1, answer.back().end());
        }
        
        return answer;
    }
};