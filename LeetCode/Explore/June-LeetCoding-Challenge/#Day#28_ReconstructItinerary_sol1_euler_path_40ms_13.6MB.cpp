class Solution {
private:
    void euler(vector<vector<int>>& g, int node, stack<int>& st){
        while(!g[node].empty()){
            int next_node = g[node].back();
            g[node].pop_back();
            euler(g, next_node, st);
        }
        st.push(node);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: build the graph
        map<string, int> airport_idx;
        for(const vector<string>& ticket: tickets){
            airport_idx[ticket[0]] = 1;
            airport_idx[ticket[1]] = 1;
        }
        
        int idx = 0;
        for(pair<const string, int>& p: airport_idx){
            p.second = ++idx;
        }
        
        const int N = idx;
        vector<string> airport_names(N + 1);
        for(const pair<string, int>& p: airport_idx){
            airport_names[p.second] = p.first;
        }
        
        vector<vector<int>> g(N + 1);
        for(const vector<string>& ticket: tickets){
            g[airport_idx[ticket[0]]].push_back(airport_idx[ticket[1]]);
        }
        
        // Step 2: sort the neighbors of each node
        for(int node = 1; node <= N; ++node){
            sort(g[node].begin(), g[node].end(), greater<int>());
        }
        
        // Step 3: save the euler path of the graph
        vector<string> answer;
        stack<int> st;
        euler(g, airport_idx["JFK"], st);
        
        while(!st.empty()){
            answer.push_back(airport_names[st.top()]);
            st.pop();
        }
        
        return answer;
    }
};