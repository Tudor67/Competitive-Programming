class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        const int N = events.size();
        
        map<int, int> maxAt;
        for(const vector<int>& EVENT: events){
            int startTime = EVENT[0];
            int endTime = EVENT[1];
            int val = EVENT[2];
            maxAt[endTime] = max(maxAt[endTime], val);
        }
        
        map<int, int> prefMaxAt;
        int prevPrefMax = 0;
        for(const pair<int, int>& P: maxAt){
            int endTime = P.first;
            int val = P.second;
            int currentMax = max(prevPrefMax, val);
            prefMaxAt[endTime] = currentMax;
            prevPrefMax = currentMax;
        }
        
        int answer = 0;
        for(const vector<int>& EVENT: events){
            int startTime = EVENT[0];
            int endTime = EVENT[1];
            int val = EVENT[2];
            
            int prevMaxVal = 0;
            auto it = prefMaxAt.lower_bound(startTime);
            if(it != prefMaxAt.begin()){
                prevMaxVal = prev(it)->second;
            }
            
            answer = max(answer, prevMaxVal + val);
        }
        
        return answer;
    }
};