class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> diffs(N);
        for(int i = 1; i < N; ++i){
            diffs[i] = nums[i] - nums[i - 1];
        }
        
        int res = 0;
        int i = 1;
        while(i < N){
            int j = i;
            while(j + 1 < N && diffs[i] == diffs[j + 1]){
                j += 1;
            }
            int k = j - i;
            res += (k * (k + 1)) / 2;
            i = j + 1;
        }
        
        return res;
    }
};