class Solution {
private:
    using Graph = map<string, vector<string>>;

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
        stack<string> st;
        st.push("JFK");

        while(!st.empty()){
            string node = st.top();

            if(G[node].empty()){
                st.pop();
                res.push_back(node);
            }else{
                string nextNode = G[node].back();
                G[node].pop_back();
                st.push(nextNode);
            }
        }
        
        reverse(res.begin(), res.end());

        return res;
    }
};