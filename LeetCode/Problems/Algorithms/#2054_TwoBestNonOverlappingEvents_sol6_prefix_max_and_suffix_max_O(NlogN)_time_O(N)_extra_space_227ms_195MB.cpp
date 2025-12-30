class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        map<int, int> prefMax;
        map<int, int> suffMax;

        for(vector<int>& event: events){
            int startTime = event[0];
            int endTime = event[1];
            int val = event[2];
            prefMax[endTime] = max(prefMax[endTime], val);
            suffMax[startTime] = max(suffMax[startTime], val);
        }

        for(auto it = next(prefMax.begin()); it != prefMax.end(); ++it){
            it->second = max(it->second, prev(it)->second);
        }

        for(auto it = next(suffMax.rbegin()); it != suffMax.rend(); ++it){
            it->second = max(it->second, prev(it)->second);
        }

        int maxSum = 0;
        for(auto it = prefMax.begin(); it != prefMax.end(); ++it){
            int t = it->first;
            int sum = it->second;
            if(t < suffMax.rbegin()->first){
                sum += suffMax.upper_bound(t)->second;
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};