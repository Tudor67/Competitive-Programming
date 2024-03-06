class Solution {
private:
    int countOneBits(int x){
        int oneBits = 0;
        while(x > 0){
            x &= (x - 1);
            oneBits += 1;
        }
        return oneBits;
    }

public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        const int N = nums.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(countOneBits(i) == k){
                res += nums[i];
            }
        }

        return res;
    }
};