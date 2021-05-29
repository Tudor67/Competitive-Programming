class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        unordered_set<int> vis;
        for(int i = 0, j = 0, sum = 0; j < N; ++j){
            while(vis.count(nums[j])){
                vis.erase(nums[i]);
                sum -= nums[i];
                i += 1;
            }
            vis.insert(nums[j]);
            sum += nums[j];
            answer = max(sum, answer);
        }
        return answer;
    }
};