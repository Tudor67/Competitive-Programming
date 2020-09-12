class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1, 0);
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
        int x_root = find(x);
        int y_root = find(y);
        if(x_root != y_root){
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        const int N = accounts.size();
        
        map<int, string> owner_name;
        map<string, int> email_idx_of;
        int email_idx = 1;
        for(int i = 0; i < N; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                string email = accounts[i][j];
                if(email_idx_of.find(email) == email_idx_of.end()){
                    owner_name[email_idx] = accounts[i][0];
                    email_idx_of[email] = email_idx;
                    email_idx += 1;
                }
            }
        }
        
        const int UNIQUE_EMAILS_CNT = email_idx;
        DSU dsu(UNIQUE_EMAILS_CNT);
        for(int i = 0; i < N; ++i){
            for(int j = 1; j < (int)accounts[i].size() - 1; ++j){
                string email1 = accounts[i][j];
                string email2 = accounts[i][j + 1];
                dsu.join(email_idx_of[email1], email_idx_of[email2]);
            }
        }
        
        map<int, set<string>> root_emails;
        for(int i = 0; i < N; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                string email = accounts[i][j];
                int email_idx = email_idx_of[email];
                int root = dsu.find(email_idx);
                root_emails[root].insert(email);
            }
        }
        
        vector<vector<string>> answer(root_emails.size());
        int i = 0;
        for(const pair<int, set<string>>& P: root_emails){
            int idx = P.first;
            string current_owner_name = owner_name[idx];
            vector<string> current_emails(P.second.begin(), P.second.end());
            
            answer[i].resize(1 + current_emails.size());
            answer[i][0] = current_owner_name;
            copy(current_emails.begin(), current_emails.end(), answer[i].begin() + 1);
            i += 1;
        }
        
        return answer;
    }
};