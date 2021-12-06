class Solution {
private:
    long long countSumsLessOrEqual(vector<int>& nums1, vector<int>& nums2, const long long& LIM){
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        long long sumCount = 0;
        int p1 = N2;
        int p2 = 0;
        int p3 = N2;
        int p4 = 0;
        for(int num1: nums1){
            if(num1 == 0){
                if(LIM >= 0){
                    sumCount += N2;
                }
            }else if(num1 > 0){
                if(LIM >= 0){
                    long long target = LIM / num1;
                    //sumCount += upper_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
                    while(p1 - 1 >= 0 && nums2[p1 - 1] > target){
                        p1 -= 1;
                    }
                    sumCount += p1;
                }else{
                    long long target = LIM / num1;
                    if(target * num1 > LIM){
                        target -= 1;
                    }
                    //sumCount += upper_bound(nums2.begin(), nums2.end(), target) - nums2.begin();
                    while(p2 < N2 && nums2[p2] <= target){
                        p2 += 1;
                    }
                    sumCount += p2;
                }
            }else if(num1 < 0){
                if(LIM >= 0){
                    long long target = LIM / num1;
                    //sumCount += N2 - (lower_bound(nums2.begin(), nums2.end(), target) - nums2.begin());
                    while(p3 - 1 >= 0 && nums2[p3 - 1] >= target){
                        p3 -= 1;
                    }
                    sumCount += (N2 - p3);
                }else{
                    long long target = LIM / num1;
                    if(target * num1 > LIM){
                        target += 1;
                    }
                    //sumCount += N2 - (lower_bound(nums2.begin(), nums2.end(), target) - nums2.begin());
                    while(p4 < N2 && nums2[p4] < target){
                        p4 += 1;
                    }
                    sumCount += (N2 - p4);
                }
            }
        }
        return sumCount;
    }
    
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
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