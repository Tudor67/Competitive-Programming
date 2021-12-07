class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int answer = 0;
        for(int startIdx = 0, endIdx = 0, currentProduct = 1; endIdx < nums.size(); ++endIdx){
            currentProduct *= nums[endIdx];
            while(startIdx <= endIdx && currentProduct >= k){
                currentProduct /= nums[startIdx];
                startIdx += 1;
            }
            answer += max(0, endIdx - startIdx + 1);
        }
        return answer;
    }
};