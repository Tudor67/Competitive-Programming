class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int N = nums.size();

        int minFlips = 0;
        int flipStatus = 0;
        vector<int> delta(N + 1);

        for(int i = 0; i < N; ++i){
            flipStatus ^= delta[i];
            if((flipStatus ^ nums[i]) == 0){
                if(i + k - 1 < N){
                    minFlips += 1;
                    flipStatus ^= 1;
                    delta[i + k] ^= 1;
                }else{
                    minFlips = -1;
                    break;
                }
            }
        }

        return minFlips;
    }
};