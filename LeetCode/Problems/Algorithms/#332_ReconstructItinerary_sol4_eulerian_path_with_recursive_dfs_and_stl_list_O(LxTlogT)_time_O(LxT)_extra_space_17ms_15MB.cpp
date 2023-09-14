class Solution {
private:
    using Graph = map<string, vector<string>>;

    void dfs(string node, Graph& G, list<string>& resList, list<string>::iterator it){
        while(!G[node].empty()){
            string nextNode = G[node].back();
            G[node].pop_back();
            list<string>::iterator nextIt = resList.insert(next(it), nextNode);
            dfs(nextNode, G, resList, nextIt);
        }
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

        list<string> resList;
        resList.push_back("JFK");
        dfs("JFK", G, resList, resList.begin());

        return vector<string>(resList.begin(), resList.end());
    }
};