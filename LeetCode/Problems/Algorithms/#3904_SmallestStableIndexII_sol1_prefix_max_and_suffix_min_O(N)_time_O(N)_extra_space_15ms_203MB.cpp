class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> suffMin(N);
        suffMin[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        int prefMax = nums[0];
        for(int i = 0; i < N; ++i){
            prefMax = max(prefMax, nums[i]);
            if(prefMax - suffMin[i] <= k){
                return i;
            }
        }

        return -1;
    }
};