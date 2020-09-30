class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int N = nums.size();
        vector<int> answer;
        
        int p1 = 0;
        int p2 = N - 1;
        while(answer.empty() && p1 < p2){
            if(nums[p1] + nums[p2] < target){
                p1 += 1;
            }else if(nums[p1] + nums[p2] > target){
                p2 -= 1;
            }else{
                answer = {p1 + 1, p2 + 1};
            }
        }
        
        return answer;
    }
};