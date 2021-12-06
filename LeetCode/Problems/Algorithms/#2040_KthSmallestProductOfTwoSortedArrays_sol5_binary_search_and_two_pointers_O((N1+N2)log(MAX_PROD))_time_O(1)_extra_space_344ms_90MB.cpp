class Solution {
private:
    long long countSumsLessOrEqual(vector<int>& nums1, const int& START_POS1, const int& END_POS1, const int& DIR1,
                                   vector<int>& nums2, const int& START_POS2, const int& END_POS2, const int& DIR2,
                                   const long long& LIM){
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        long long sumCount = 0;
        for(int p1 = START_POS1, p2 = START_POS2; p1 != END_POS1; p1 += DIR1){
            while(p2 != END_POS2 && 1LL * nums1[p1] * nums2[p2] > LIM){
                p2 += DIR2;
            }
            sumCount += abs(END_POS2 - p2);
        }
        return sumCount;
    }
    
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        int idx1 = lower_bound(nums1.begin(), nums1.end(), 0) - nums1.begin();
        int idx2 = lower_bound(nums2.begin(), nums2.end(), 0) - nums2.begin();
        
        long long l = min({1LL * nums1.front() * nums2.front(), 1LL * nums1.front() * nums2.back(),
                           1LL * nums1.back() * nums2.front(), 1LL * nums1.back() * nums2.back()}) - 1;
        long long r = max({1LL * nums1.front() * nums2.front(), 1LL * nums1.front() * nums2.back(),
                           1LL * nums1.back() * nums2.front(), 1LL * nums1.back() * nums2.back()});
        
        while(l != r){
            long long mid = (l + r + 1) / 2;
            long long sumCount = 0;
            if(mid >= 0){
                sumCount = 1LL * (N1 - idx1) * idx2 + 1LL * idx1 * (N2 - idx2) +
                           countSumsLessOrEqual(nums1, idx1, N1, 1, nums2, N2 - 1, idx2 - 1, -1, mid) +
                           countSumsLessOrEqual(nums1, idx1 - 1, -1, -1, nums2, 0, idx2, 1, mid);
            }else{
                sumCount = countSumsLessOrEqual(nums1, N1 - 1, idx1 - 1, -1, nums2, idx2 - 1, -1, -1, mid) +
                           countSumsLessOrEqual(nums1, 0, idx1, 1, nums2, idx2, N2, 1, mid);
            }
            if(sumCount < k){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r + 1;
    }
};