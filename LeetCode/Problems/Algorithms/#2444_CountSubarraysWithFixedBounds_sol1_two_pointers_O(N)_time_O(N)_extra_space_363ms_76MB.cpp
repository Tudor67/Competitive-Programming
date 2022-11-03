class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int N = nums.size();
        const int INF = 1e9;
        
        long long res = 0;
        vector<int> firstRightPosOfMin(N + 1, INF);
        vector<int> firstRightPosOfMax(N + 1, INF);
        
        int startPos = 0;
        while(startPos < N){
            int endPos = startPos;
            while(endPos < N && minK <= nums[endPos] && nums[endPos] <= maxK){
                endPos += 1;
            }
            
            // nums[startPos .. endPos - 1]: the longest subarray that includes elements
            //                               nums[startPos], nums[startPos + 1], ..., nums[endPos - 1]
            //                               such that all elements are in the range [minK, maxK]
            for(int i = endPos - 1; i >= startPos; --i){
                if(nums[i] == minK){
                    firstRightPosOfMin[i] = i;
                }else{
                    firstRightPosOfMin[i] = firstRightPosOfMin[i + 1];
                }
                if(nums[i] == maxK){
                    firstRightPosOfMax[i] = i;
                }else{
                    firstRightPosOfMax[i] = firstRightPosOfMax[i + 1];
                }
            }
            
            for(int i = startPos; i <= endPos - 1; ++i){
                if(firstRightPosOfMin[i] != INF && firstRightPosOfMax[i] != INF){
                    res += endPos - max(firstRightPosOfMin[i], firstRightPosOfMax[i]);
                }
            }
            
            startPos = endPos + 1;
        }
        
        return res;
    }
};