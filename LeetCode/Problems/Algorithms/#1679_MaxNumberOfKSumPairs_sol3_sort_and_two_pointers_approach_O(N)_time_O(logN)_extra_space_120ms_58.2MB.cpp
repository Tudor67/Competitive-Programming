class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = 0;
        for(int i = 0, j = (int)nums.size() - 1; i < j; ++i){
            for(; i < j && nums[i] + nums[j] > k; --j);
            if(i < j && nums[i] + nums[j] == k){
                answer += 1;
                j -= 1;
            }
        }
        return answer;
    }
};