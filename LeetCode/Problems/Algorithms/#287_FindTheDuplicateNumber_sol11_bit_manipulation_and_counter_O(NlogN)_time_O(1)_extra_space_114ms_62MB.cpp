class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = (int)nums.size() - 1;
        const int MAX_BIT = floor(log2(N));

        int duplicate = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int targetCount = 0;
            for(int num = 1; num <= N; ++num){
                if((num >> bit) & 1){
                    targetCount += 1;
                }
            }

            int count = 0;
            for(int num: nums){
                if((num >> bit) & 1){
                    count += 1;
                }
            }

            if(targetCount < count){
                duplicate |= (1 << bit);
            }
        }

        return duplicate;
    }
};