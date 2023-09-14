class Solution {
private:
    using Graph = map<string, vector<string>>;

    void dfs(string node, Graph& G, vector<string>& res){
        while(!G[node].empty()){
            string nextNode = G[node].back();
            G[node].pop_back();
            dfs(nextNode, G, res);
        }
        res.push_back(node);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        const int T = tickets.size();

        Graph G;
        for(int i = 0; i < T; ++i){
            string from = tickets[i][0];
            string to = tickets[i][1];
            G[from].push_back(to);
        }

        for(pair<const string, vector<string>>& P: G){
            vector<string>& v = P.second;
            sort(v.rbegin(), v.rend());
        }

        vector<string> res;
        dfs("JFK", G, res);

        reverse(res.begin(), res.end());

        return res;
    }
};