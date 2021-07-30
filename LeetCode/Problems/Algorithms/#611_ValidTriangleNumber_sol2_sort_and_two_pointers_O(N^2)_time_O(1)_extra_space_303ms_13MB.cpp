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
        for(int i = 0; i < N - 2; ++i){
            int k = i + 2;
            for(int j = i + 1; j < N - 1; ++j){
                k = max(k, j + 1);
                while(k < N && nums[i] + nums[j] > nums[k]){
                    k += 1;
                }
                triplets += (k - 1 - j);
            }
        }
        
        return triplets;
    }
};