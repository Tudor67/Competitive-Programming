class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const int N = nums.size();
        const int ZEROS = count(nums.begin(), nums.end(), 0);
        const int XOR = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

        if(ZEROS == N){
            return 0;
        }

        if(XOR == 0){
            return N - 1;
        }

        return N;
    }
};