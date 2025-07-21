class Solution {
public:
    int maximumLength(vector<int>& nums) {
        const int N = nums.size();

        int evenCount = 0;
        int oddCount = 0;
        for(int num: nums){
            if(num % 2 == 0){
                evenCount += 1;
            }else{
                oddCount += 1;
            }
        }

        int alternatingCount = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] % 2 != nums[i + 1] % 2){
                alternatingCount += 1;
            }
        }

        return max({oddCount, evenCount, 1 + alternatingCount});
    }
};