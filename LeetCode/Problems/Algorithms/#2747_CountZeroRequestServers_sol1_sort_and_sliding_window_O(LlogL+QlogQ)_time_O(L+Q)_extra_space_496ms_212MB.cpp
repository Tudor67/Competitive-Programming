class Solution {
public:
    vector<int> countServers(int N, vector<vector<int>>& logs, int x, vector<int>& queries) {
        const int L = logs.size();
        const int Q = queries.size();
        
        // Step 1: sort the logs (increasing order of time)
        vector<pair<int, int>> sortedLogs(L);
        for(int i = 0; i < L; ++i){
            sortedLogs[i] = {logs[i][0], logs[i][1]};
        }
        
        sort(sortedLogs.begin(), sortedLogs.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 return LHS.second < RHS.second;
             });
        
        // Step 2: sort the queries (increasing order of time)
        vector<int> pQ(Q);
        iota(pQ.begin(), pQ.end(), 0);
        sort(pQ.begin(), pQ.end(),
            [&](int lhs, int rhs){
                return queries[lhs] < queries[rhs];
            });
        
        // Step 3: process the sorted queries with a sliding window approach
        //         for the current query we have the window [minTimeOfQuery, maxTimeOfQuery]:
        //             * add in freq map servers with time <= maxTimeOfQuery
        //             * remove from freq map servers with time < minTimeOfQuery
        //         the number of servers that did not reveive any requests
        //         is (totalServers - activeServersOfCurrentWindow) = (totalServers - (int)freq.size())
        vector<int> res(Q);
        map<int, int> freq;
        int lStartIdx = 0;
        int lEndIdx = -1;
        
        for(int qIdx: pQ){
            int minTimeOfQuery = queries[qIdx] - x;
            int maxTimeOfQuery = queries[qIdx];
            
            while(lEndIdx + 1 < L && sortedLogs[lEndIdx + 1].second <= maxTimeOfQuery){
                int serverId = sortedLogs[lEndIdx + 1].first;
                freq[serverId] += 1;
                lEndIdx += 1;
            }
            
            while(lStartIdx < L && sortedLogs[lStartIdx].second < minTimeOfQuery){
                int serverId = sortedLogs[lStartIdx].first;
                freq[serverId] -= 1;
                if(freq[serverId] == 0){
                    freq.erase(serverId);
                }
                lStartIdx += 1;
            }
            
            res[qIdx] = N - (int)freq.size();
        }
        
        return res;
    }
};