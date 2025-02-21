class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int N = nums.size();

        string res(N, '0');
        for(int i = 0; i < N; ++i){
            res[i] = nums[i][i] ^ 1;
        }

        return res;
    }
};