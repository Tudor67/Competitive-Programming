class Solution {
public:
    vector<int> findAllPeople(int N, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> g(N);
        for(const vector<int>& XYT: meetings){
            int x = XYT[0];
            int y = XYT[1];
            int t = XYT[2];
            g[x].emplace_back(t, y);
            g[y].emplace_back(t, x);
        }
        g[0].emplace_back(0, firstPerson);
        g[firstPerson].emplace_back(0, 0);
        
        const int INF = 1e8;
        // minTime[y]: min time when the yth person will receive the secret
        vector<int> minTime(N, INF);
        set<pair<int, int>> stateSet;
        stateSet.emplace(0, 0);
        minTime[0] = 0;
        
        while(!stateSet.empty()){
            int x = stateSet.begin()->second;
            stateSet.erase(stateSet.begin());
            
            for(const pair<int, int>& P: g[x]){
                int t = P.first;
                int y = P.second;
                if(minTime[x] <= t && t < minTime[y]){
                    stateSet.erase({minTime[y], y});
                    minTime[y] = t;
                    stateSet.emplace(minTime[y], y);
                }
            }
        }
        
        vector<int> answer;
        for(int x = 0; x < N; ++x){
            if(minTime[x] != INF){
                answer.push_back(x);
            }
        }
        
        return answer;
    }
};