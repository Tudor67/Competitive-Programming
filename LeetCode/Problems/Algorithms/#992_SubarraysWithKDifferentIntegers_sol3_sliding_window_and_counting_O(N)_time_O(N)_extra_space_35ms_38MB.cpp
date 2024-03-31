class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        const int N = nums.size();

        int subarraysCount = 0;
        vector<int> f1(N + 1);
        vector<int> f2(N + 1);
        int distinct2 = 0;
        int distinct1 = 0;
        int l2 = 0;
        int l1 = 0;

        for(int r = 0; r < N; ++r){
            // longest subarray nums[l2 .. r] with k distinct integers
            f2[nums[r]] += 1;
            distinct2 += (int)(f2[nums[r]] == 1);
            while(l2 <= r && distinct2 > k){
                distinct2 -= (int)(f2[nums[l2]] == 1);
                f2[nums[l2]] -= 1;
                l2 += 1;
            }

            // shortest subarray nums[l1 .. r] with k distinct integers
            f1[nums[r]] += 1;
            distinct1 += (int)(f1[nums[r]] == 1);
            while(l1 <= r && (distinct1 > k || f1[nums[l1]] >= 2)){
                distinct1 -= (int)(f1[nums[l1]] == 1);
                f1[nums[l1]] -= 1;
                l1 += 1;
            }

            if(distinct1 == k){
                // number of subarrays with k distinct integers ending with nums[r]: l1 - l2 + 1
                // all valid subarrays: nums[l2 .. r], nums[l2 + 1 .. r], ..., nums[l1 .. r]
                subarraysCount += l1 - l2 + 1;
            }
        }

        return subarraysCount;
    }
};