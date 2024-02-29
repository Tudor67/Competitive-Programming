class Solution {
public:
    vector<int> findAllPeople(int N, vector<vector<int>>& meetings, int firstPerson) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> G(N);
        for(const vector<int>& MEETING: meetings){
            int a = MEETING[0];
            int b = MEETING[1];
            int t = MEETING[2];
            G[a].push_back({b, t});
            G[b].push_back({a, t});
        }
        
        G[0].push_back({firstPerson, 0});

        vector<int> receivalTime(N, INF);
        set<pair<int, int>> statesSet;
        receivalTime[0] = 0;
        statesSet.insert({receivalTime[0], 0});

        while(!statesSet.empty()){
            int person = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            for(const pair<int, int>& P: G[person]){
                int nextPerson = P.first;
                int t = P.second;
                if(receivalTime[person] <= t && t < receivalTime[nextPerson]){
                    statesSet.erase({receivalTime[nextPerson], nextPerson});
                    receivalTime[nextPerson] = t;
                    statesSet.insert({receivalTime[nextPerson], nextPerson});
                }
            }
        }

        vector<int> res;
        for(int person = 0; person < N; ++person){
            if(receivalTime[person] != INF){
                res.push_back(person);
            }
        }

        return res;
    }
};