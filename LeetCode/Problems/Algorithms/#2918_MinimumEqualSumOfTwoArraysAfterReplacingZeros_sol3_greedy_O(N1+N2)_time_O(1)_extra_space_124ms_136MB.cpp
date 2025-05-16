class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        long long sum1 = accumulate(nums1.begin(), nums1.end(), (long long)0);
        int zeros1 = count(nums1.begin(), nums1.end(), 0);

        long long sum2 = accumulate(nums2.begin(), nums2.end(), (long long)0);
        int zeros2 = count(nums2.begin(), nums2.end(), 0);

        long long minValidSum = max(sum1 + zeros1, sum2 + zeros2);
        if((sum1 != minValidSum && zeros1 == 0) ||
           (sum2 != minValidSum && zeros2 == 0)){
            minValidSum = -1;
        }

        return minValidSum;
    }
};