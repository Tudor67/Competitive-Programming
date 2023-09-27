class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = (int)nums.size() - 1;
        const int MAX_BIT = floor(log2(N));

        vector<int> targetCount(MAX_BIT + 1);
        for(int num = 1; num <= N; ++num){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num >> bit) & 1){
                    targetCount[bit] += 1;
                }
            }
        }

        vector<int> count(MAX_BIT + 1);
        for(int num: nums){
            for(int bit = 0; bit <= MAX_BIT; ++bit){
                if((num >> bit) & 1){
                    count[bit] += 1;
                }
            }
        }

        int duplicate = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            if(targetCount[bit] < count[bit]){
                duplicate |= (1 << bit);
            }
        }

        return duplicate;
    }
};