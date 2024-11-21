class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> res(N - k + 1, -1);

        int i = 0;
        while(i < N){
            int j = i + 1;
            while(j < N && nums[j - 1] + 1 == nums[j]){
                j += 1;
            }
            
            while(i + k - 1 < j){
                res[i] = nums[i + k - 1];
                i += 1;
            }

            i = j;
        }

        return res;
    }
};