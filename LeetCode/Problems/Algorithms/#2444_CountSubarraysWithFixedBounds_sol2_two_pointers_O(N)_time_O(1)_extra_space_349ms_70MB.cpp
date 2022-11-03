class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int N = nums.size();
        const int INF = 1e9;
        
        long long res = 0;
        int startPos = 0;
        while(startPos < N){
            int endPos = startPos;
            while(endPos < N && minK <= nums[endPos] && nums[endPos] <= maxK){
                endPos += 1;
            }
            
            // nums[startPos .. endPos - 1]: the longest subarray that includes elements
            //                               nums[startPos], nums[startPos + 1], ..., nums[endPos - 1]
            //                               such that all elements are in the range [minK, maxK]
            int minKPos = startPos;
            int maxKPos = startPos;
            for(int i = startPos; i <= endPos - 1; ++i){
                minKPos = max(minKPos, i);
                while(minKPos < endPos && nums[minKPos] != minK){
                    minKPos += 1;
                }
                
                maxKPos = max(maxKPos, i);
                while(maxKPos < endPos && nums[maxKPos] != maxK){
                    maxKPos += 1;
                }
                
                if(minKPos < endPos && maxKPos < endPos){
                    res += endPos - max(minKPos, maxKPos);
                }
            }
            
            startPos = endPos + 1;
        }
        
        return res;
    }
};