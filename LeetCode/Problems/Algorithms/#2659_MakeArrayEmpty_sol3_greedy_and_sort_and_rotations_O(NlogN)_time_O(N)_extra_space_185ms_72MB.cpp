class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return nums[lhs] < nums[rhs];
             });

        long long totalOperations = N;
        for(int i = 1; i < N; ++i){
            if(p[i - 1] > p[i]){
                totalOperations += (N - i);
            }
        }

        return totalOperations;
    }
};