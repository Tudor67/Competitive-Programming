class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        vector<int> firstIndexOf(2 * N + 1, N);
        firstIndexOf[0 + N] = -1;

        int prefBalance = 0;
        for(int i = 0; i < N; ++i){
            prefBalance += 2 * nums[i] - 1;
            res = max(res, i - firstIndexOf[prefBalance + N]);
            firstIndexOf[prefBalance + N] = min(firstIndexOf[prefBalance + N], i);
        }

        return res;
    }
};