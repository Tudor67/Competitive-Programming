class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        const int N = intervals.size();
        const int Q = queries.size();
        
        vector<pair<int, int>> queryIdxPairs(Q);
        for(int i = 0; i < Q; ++i){
            queryIdxPairs[i] = {queries[i], i};
        }
        
        sort(intervals.begin(), intervals.end());
        sort(queryIdxPairs.begin(), queryIdxPairs.end());
        
        vector<int> answer(Q);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int intervalIdx = 0;
        for(int i = 0; i < Q; ++i){
            int query = queryIdxPairs[i].first;
            int queryIdx = queryIdxPairs[i].second;
            
            while(intervalIdx < N && intervals[intervalIdx][0] <= query){
                minHeap.push({intervals[intervalIdx][1] - intervals[intervalIdx][0] + 1, intervals[intervalIdx][1]});
                intervalIdx += 1;
            }
            
            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }
            
            if(minHeap.empty()){
                answer[queryIdx] = -1;
            }else{
                answer[queryIdx] = minHeap.top().first;
            }
        }
        
        return answer;
    }
};