class Solution {
private:
    void euler(map<string, multiset<string>>& g, string node, vector<string>& answer){
        while(!g[node].empty()){
            string next_node = *g[node].begin();
            g[node].erase(g[node].begin());
            euler(g, next_node, answer);
        }
        answer.push_back(node);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> next_airports;
        for(const vector<string>& ticket: tickets){
            next_airports[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> answer;
        euler(next_airports, "JFK", answer);
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};