class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        int minOps = 0;
        
        vector<int> delta(N + 1);
        for(int i = 0; i < N; ++i){
            if(i >= 1){
                delta[i] ^= delta[i - 1];
            }

            if(i + 2 < N && (nums[i] ^ delta[i]) == 0){
                minOps += 1;
                delta[i] ^= 1;
                delta[i + 3] ^= 1;
            }

            if((nums[i] ^ delta[i]) == 0){
                return -1;
            }
        }

        return minOps;
    }
};