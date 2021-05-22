class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        long long answer = 0;
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            answer += (nums[j] - nums[i]);
        }
        
        return answer;
    }
};