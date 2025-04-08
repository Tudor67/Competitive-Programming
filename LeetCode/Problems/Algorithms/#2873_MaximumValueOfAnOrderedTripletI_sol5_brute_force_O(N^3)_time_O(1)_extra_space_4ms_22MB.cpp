class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                for(int k = j + 1; k < N; ++k){
                    long long a = nums[i];
                    long long b = nums[j];
                    long long c = nums[k];
                    res = max(res, (a - b) * c);
                }
            }
        }

        return res;
    }
};