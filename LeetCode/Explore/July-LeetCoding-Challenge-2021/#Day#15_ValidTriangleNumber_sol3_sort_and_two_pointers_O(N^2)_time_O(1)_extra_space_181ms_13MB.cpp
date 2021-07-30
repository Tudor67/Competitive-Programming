class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int N = nums.size();
        
        for(int i = 0; i < N - 1; ++i){
            for(int j = i + 1; j < N; ++j){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
        
        int triplets = 0;
        for(int k = 2; k < N; ++k){
            int i = 0;
            int j = k - 1;
            while(i < j){
                if(nums[i] + nums[j] <= nums[k]){
                    i += 1;
                }else{
                    triplets += (j - i);
                    j -= 1;
                }
            }
        }
        
        return triplets;
    }
};