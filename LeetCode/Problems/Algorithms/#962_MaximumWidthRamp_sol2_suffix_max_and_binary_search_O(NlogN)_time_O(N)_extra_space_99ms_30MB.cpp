class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> idxOfSuffMax(N);
        idxOfSuffMax[N - 1] = N - 1;
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] > nums[idxOfSuffMax[i + 1]]){
                idxOfSuffMax[i] = i;
            }else{
                idxOfSuffMax[i] = idxOfSuffMax[i + 1];
            }
        }
        
        int maxRampWidth = 0;
        for(int i = 0; i + 1 < N; ++i){
            int l = i + 1;
            int r = N - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(nums[i] <= nums[idxOfSuffMax[mid]]){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            
            if(nums[i] <= nums[idxOfSuffMax[r]]){
                int rampWidth = idxOfSuffMax[r] - i;
                maxRampWidth = max(maxRampWidth, rampWidth);
            }
        }
        
        return maxRampWidth;
    }
};