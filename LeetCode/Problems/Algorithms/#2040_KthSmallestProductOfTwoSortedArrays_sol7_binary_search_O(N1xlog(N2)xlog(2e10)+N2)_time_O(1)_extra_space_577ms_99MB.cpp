class Solution {
private:
    long long countPairsWithProductLessOrEqual(const vector<int>& nums1, const vector<int>& nums2, long long threshold){
        long long validPairs = 0;
        for(long long num1: nums1){
            if(num1 < 0){
                long long target = threshold / num1;
                if(target * num1 > threshold){
                    target += 1;
                }
                validPairs += nums2.end() - lower_bound(nums2.begin(), nums2.end(), target);
            }else if(num1 == 0){
                if(threshold >= 0){
                    validPairs += nums2.size();
                }
            }else if(num1 > 0){
                long long target = threshold / num1;
                if(target * num1 > threshold){
                    target -= 1;
                }
                validPairs += upper_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
            }
        }
        return validPairs;
    }

public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10;
        long long r =  1e10;
        while(l != r){
            long long mid = (l + r) / 2;
            if(2 * mid > l + r){
                mid -= 1;
            }
            if(countPairsWithProductLessOrEqual(nums1, nums2, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }
};