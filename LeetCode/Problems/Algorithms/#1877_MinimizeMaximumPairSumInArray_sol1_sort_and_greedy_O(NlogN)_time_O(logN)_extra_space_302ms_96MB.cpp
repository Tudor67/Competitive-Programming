class Solution {
public:
    int minPairSum(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        for(int i = 0; i < N / 2; ++i){
            answer = max(answer, nums[i] + nums[N - 1 - i]);
        }
        
        return answer;
    }
};