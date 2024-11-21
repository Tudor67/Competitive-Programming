class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> res(N - k + 1);
        for(int i = 0; i + k - 1 < N; ++i){
            bool areConsecutive = true;
            for(int j = i + 1; j <= i + k - 1; ++j){
                if(nums[j - 1] + 1 != nums[j]){
                    areConsecutive = false;
                }
            }
            
            if(areConsecutive){
                res[i] = nums[i + k - 1];
            }else{
                res[i] = -1;
            }
        }

        return res;
    }
};