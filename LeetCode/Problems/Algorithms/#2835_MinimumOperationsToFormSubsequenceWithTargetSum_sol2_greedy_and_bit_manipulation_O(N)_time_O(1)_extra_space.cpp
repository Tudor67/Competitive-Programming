class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), (long long)0);
        const int MAX_BIT = 30;

        if(TOTAL_SUM < target){
            return -1;
        }

        map<int, int> numToBitIndex;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            numToBitIndex[1 << bit] = bit;
        }

        vector<int> f(MAX_BIT + 1);
        for(int num: nums){
            f[numToBitIndex[num]] += 1;
        }

        int res = 0;
        while(target > 0){
            int targetBit = numToBitIndex[target - (target & (target - 1))];

            for(int bit = 1; bit <= targetBit; ++bit){
                f[bit] += f[bit - 1] / 2;
                f[bit - 1] %= 2;
            }
            
            if(f[targetBit] == 0){
                int rightBit = targetBit + 1;
                while(rightBit < MAX_BIT && f[rightBit] == 0){
                    rightBit += 1;
                }

                for(int bit = rightBit - 1; bit >= targetBit; --bit){
                    f[bit + 1] -= 1;
                    f[bit] += 2;
                    res += 1;
                }
            }

            f[targetBit] -= 1;
            target -= (1 << targetBit);
        }

        return res;
    }
};