class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        const int N = nums.size();

        int validTuples = 0;
        unordered_map<int, int> count;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int prod = nums[i] * nums[j];
                validTuples += 8 * count[prod];
                count[prod] += 1;
            }
        }

        return validTuples;
    }
};