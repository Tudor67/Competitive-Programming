class Solution {
private:
    long long countSumsLessOrEqual(vector<int>& nums1, vector<int>& nums2, const long long& LIM){
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        long long sumCount = 0;
        for(int num1: nums1){
            if(num1 == 0){
                if(LIM >= 0){
                    sumCount += N2;
                }
            }else if(num1 > 0){
                long long target = LIM / num1;
                if(target * num1 > LIM){
                    target -= 1;
                }
                sumCount += upper_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
            }else if(num1 < 0){
                long long target = LIM / num1;
                if(target * num1 > LIM){
                    target += 1;
                }
                sumCount += N2 - (lower_bound(nums2.begin(), nums2.end(), target) - nums2.begin());
            }
        }
        return sumCount;
    }
    
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        if(N1 > N2){
            return kthSmallestProduct(nums2, nums1, k);
        }
        
        long long l = min({1LL * nums1.front() * nums2.front(), 1LL * nums1.front() * nums2.back(), 
                           1LL * nums1.back() * nums2.front(), 1LL * nums1.back() * nums2.back()}) - 1;
        long long r = max({1LL * nums1.front() * nums2.front(), 1LL * nums1.front() * nums2.back(), 
                           1LL * nums1.back() * nums2.front(), 1LL * nums1.back() * nums2.back()});
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(countSumsLessOrEqual(nums1, nums2, mid) < k){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r + 1;
    }
};