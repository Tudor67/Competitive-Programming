class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        const int N = (int)nums.size() - 2;

        // Step 1: compute abXOR
        int abXOR = 0;
        for(int i = 0; i < N; ++i){
            abXOR ^= i;
        }

        for(int num: nums){
            abXOR ^= num;
        }

        // Step 2: split abXOR into a and b using the lsb of abXOR
        int a = 0;
        int b = 0;
        int splitMask = abXOR - (abXOR & (abXOR - 1));
        for(int i = 0; i < N; ++i){
            if(i & splitMask){
                a ^= i;
            }else{
                b ^= i;
            }
        }

        for(int num: nums){
            if(num & splitMask){
                a ^= num;
            }else{
                b ^= num;
            }
        }

        return {a, b};
    }
};