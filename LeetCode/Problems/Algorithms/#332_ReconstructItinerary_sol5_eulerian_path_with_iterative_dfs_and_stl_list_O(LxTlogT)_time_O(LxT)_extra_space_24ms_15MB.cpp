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

        list<string> resList;
        resList.push_back("JFK");

        stack<pair<string, list<string>::iterator>> st;
        st.push({"JFK", resList.begin()});

        while(!st.empty()){
            string node = st.top().first;
            list<string>::iterator it = st.top().second;

            if((int)G[node].size() <= 1){
                st.pop();
            }

            if(!G[node].empty()){
                string nextNode = G[node].back();
                G[node].pop_back();
                list<string>::iterator nextIt = resList.insert(next(it), nextNode);
                st.push({nextNode, nextIt});
            }
        }

        return vector<string>(resList.begin(), resList.end());
    }
};