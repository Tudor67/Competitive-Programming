class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int, int> prefMaxVal;
        for(const vector<int>& EVENT: events){
            int endTime = EVENT[1];
            int val = EVENT[2];
            prefMaxVal[endTime] = max(prefMaxVal[endTime], val);
        }

        for(auto it = next(prefMaxVal.begin()); it != prefMaxVal.end(); ++it){
            it->second = max(it->second, prev(it)->second);
        }

        int maxSum = 0;
        for(const vector<int>& EVENT: events){
            int startTime = EVENT[0];
            int sum = EVENT[2];
            auto it = prefMaxVal.lower_bound(startTime);
            if(it != prefMaxVal.begin()){
                sum += prev(it)->second;
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};