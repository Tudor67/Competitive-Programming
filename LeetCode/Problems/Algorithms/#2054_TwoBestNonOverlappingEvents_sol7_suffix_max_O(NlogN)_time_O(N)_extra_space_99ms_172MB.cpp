class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int, int> suffMax;
        for(vector<int>& event: events){
            int startTime = event[0];
            int endTime = event[1];
            int val = event[2];
            suffMax[startTime] = max(suffMax[startTime], val);
        }

        for(auto it = next(suffMax.rbegin()); it != suffMax.rend(); ++it){
            it->second = max(it->second, prev(it)->second);
        }

        int maxSum = 0;
        for(vector<int>& event: events){
            int endTime = event[1];
            int sum = event[2];
            if(endTime < suffMax.rbegin()->first){
                sum += suffMax.upper_bound(endTime)->second;
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};