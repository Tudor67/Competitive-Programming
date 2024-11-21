class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> res(N - k + 1, -1);
        
        int sum = 0;
        for(int i = 0; i < N; ++i){
            if(i - 1 >= 0){
                sum += (int)(nums[i - 1] + 1 == nums[i]);
            }
            
            if(i - k >= 0){
                sum -= (int)(nums[i - k] + 1 == nums[i - k + 1]);
            }

            if(i >= k - 1 && sum == k - 1){
                res[i - k + 1] = nums[i];
            }
        }

        return res;
    }
};