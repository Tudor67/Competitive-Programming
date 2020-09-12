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
        vector<set<string>> emails(N);
        for(int i = 0; i < N; ++i){
            for(int j = 1; j < accounts[i].size(); ++j){
                emails[i].insert(accounts[i][j]);
            }
        }
        
        DSU dsu(N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(accounts[i][0] == accounts[j][0]){
                    for(const string& EMAIL: emails[i]){
                        if(emails[j].count(EMAIL)){
                            dsu.join(i, j);
                            break;
                        }
                    }
                }
            }
        }
        
        for(int x = 0; x < N; ++x){
            int x_root = dsu.find(x);
            if(x_root != x){
                emails[x_root].insert(emails[x].begin(), emails[x].end());
            }
        }
        
        vector<vector<string>> answer;
        for(int x = 0; x < N; ++x){
            int x_root = dsu.find(x);
            if(x == x_root){
                vector<string> all_emails(emails[x].begin(), emails[x].end());
                answer.push_back(vector<string>(1 + all_emails.size()));
                answer.back()[0] = accounts[x][0];
                copy(all_emails.begin(), all_emails.end(), answer.back().begin() + 1);
            }
        }
        
        return answer;
    }
};