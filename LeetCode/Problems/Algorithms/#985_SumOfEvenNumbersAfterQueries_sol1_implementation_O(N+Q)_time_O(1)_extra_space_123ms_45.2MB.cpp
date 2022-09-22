class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        
        int sumOfEvenNums = 0;
        for(int num: nums){
            if(num % 2 == 0){
                sumOfEvenNums += num;
            }
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int val = queries[i][0];
            int index = queries[i][1];
            if(nums[index] % 2 == 0){
                sumOfEvenNums -= nums[index];
            }
            nums[index] += val;
            if(nums[index] % 2 == 0){
                sumOfEvenNums += nums[index];
            }
            answer[i] = sumOfEvenNums;
        }
        
        return answer;
    }
};