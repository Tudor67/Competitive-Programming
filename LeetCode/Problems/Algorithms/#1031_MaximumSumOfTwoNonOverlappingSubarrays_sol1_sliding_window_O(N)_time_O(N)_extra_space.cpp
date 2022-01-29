class Solution {
private:
    int computeMaxSum(vector<int>& nums, int firstLen, int secondLen){
        const int N = nums.size();
        
        // maxSumFirstLen[i]: max sum of a subarray of length firstLen from nums[0 .. i]
        vector<int> maxSumFirstLen(N);
        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += nums[i];
            if(i >= firstLen){
                sum -= nums[i - firstLen];
            }
            if(i >= firstLen - 1){
                if(i - 1 >= 0){
                    maxSumFirstLen[i] = max(maxSumFirstLen[i - 1], sum);
                }else{
                    maxSumFirstLen[i] = sum;
                }
            }
        }
        
        int answer = 0;
        sum = 0;
        for(int i = 0; i < N; ++i){
            sum += nums[i];
            if(i >= secondLen){
                sum -= nums[i - secondLen];
                answer = max(answer, maxSumFirstLen[i - secondLen] + sum);
            }
        }
        
        return answer;
    }
    
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(computeMaxSum(nums, firstLen, secondLen),
                   computeMaxSum(nums, secondLen, firstLen));
    }
};