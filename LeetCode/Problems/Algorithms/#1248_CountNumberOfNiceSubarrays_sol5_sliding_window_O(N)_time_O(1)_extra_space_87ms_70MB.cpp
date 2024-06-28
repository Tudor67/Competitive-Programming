class Solution {
private:
    int countSubarraysWithAtLeastKOddNumbers(vector<int>& nums, int k){
        const int N = nums.size();

        int res = 0;
        int l = 0;
        int oddFreq = 0;
        for(int r = 0; r < N; ++r){
            oddFreq += (nums[r] % 2);
            while(l <= r && (oddFreq > k || nums[l] % 2 == 0)){
                oddFreq -= (nums[l] % 2);
                l += 1;
            }
            if(oddFreq == k){
                res += (l + 1);
            }
        }

        return res;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (countSubarraysWithAtLeastKOddNumbers(nums, k) -
                countSubarraysWithAtLeastKOddNumbers(nums, k + 1));
    }
};