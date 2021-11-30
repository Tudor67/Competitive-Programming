class Solution {
private:
    void bfs(const vector<string>& ACCOUNT, unordered_set<string>& vis, unordered_map<string, vector<string>>& g, vector<string>& groupNodes){
        const string& FIRST_EMAIL = ACCOUNT[1];
        
        queue<string> q;
        q.push(FIRST_EMAIL);
        vis.insert(FIRST_EMAIL);
        
        while(!q.empty()){
            string email = q.front();
            q.pop();
            
            groupNodes.push_back(email);
            
            for(string& nextEmail: g[email]){
                if(!vis.count(nextEmail)){
                    q.push(nextEmail);
                    vis.insert(nextEmail);
                }
            }
        }
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> g;
        for(const vector<string>& ACCOUNT: accounts){
            for(int j = 2; j < (int)ACCOUNT.size(); ++j){
                const string& X = ACCOUNT[j - 1];
                const string& Y = ACCOUNT[j];
                g[X].push_back(Y);
                g[Y].push_back(X);
            }
        }
        
        unordered_set<string> vis;
        vector<vector<string>> answer;
        for(const vector<string>& ACCOUNT: accounts){
            const string& ACCOUNT_NAME = ACCOUNT[0];
            const string& FIRST_EMAIL = ACCOUNT[1];
            if(!vis.count(FIRST_EMAIL)){
                answer.push_back({ACCOUNT_NAME});
                bfs(ACCOUNT, vis, g, answer.back());
                sort(answer.back().begin() + 1, answer.back().end());
            }
        }
        
        return answer;
    }
};