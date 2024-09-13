class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int res = 0;
        int mask = 0;

        for(int bit = 29; bit >= 0; --bit){
            mask += (1 << bit);

            int ops = 0;
            int groupAND = 0;
            for(int num: nums){
                if(groupAND){
                    groupAND &= num;
                    ops += 1;
                }else if(num & mask){
                    groupAND = num & mask;
                }
            }

            if(groupAND){
                ops += 1;
            }

            if(ops > k){
                res |= (1 << bit);
                mask -= (1 << bit);
            }
        }

        return res;
    }
};