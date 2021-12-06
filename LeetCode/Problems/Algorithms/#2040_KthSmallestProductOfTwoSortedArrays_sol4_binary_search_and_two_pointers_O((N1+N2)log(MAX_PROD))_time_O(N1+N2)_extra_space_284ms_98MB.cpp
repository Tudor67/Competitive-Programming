class Solution {
private:
    long long countSumsLessOrEqual(vector<int>& nums1, vector<int>& nums2, const long long& LIM){
        long long sumCount = 0;
        int p2 = (int)nums2.size() - 1;
        for(int num1: nums1){
            while(p2 >= 0 && 1LL * num1 * nums2[p2] > LIM){
                p2 -= 1;
            }
            sumCount += (p2 + 1);
        }
        return sumCount;
    }
    
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int>::iterator it1 = lower_bound(nums1.begin(), nums1.end(), 0);
        vector<int>::iterator it2 = lower_bound(nums2.begin(), nums2.end(), 0);
        vector<int> neg1(nums1.begin(), it1), pos1(it1, nums1.end());
        vector<int> neg2(nums2.begin(), it2), pos2(it2, nums2.end());
        vector<int> pos1Rev(pos1.rbegin(), pos1.rend());
        vector<int> neg1Rev(neg1.rbegin(), neg1.rend());
        vector<int> pos2Rev(pos2.rbegin(), pos2.rend());
        vector<int> neg2Rev(neg2.rbegin(), neg2.rend());
        
        long long l = min({1LL * nums1.front() * nums2.front(), 1LL * nums1.front() * nums2.back(),
                           1LL * nums1.back() * nums2.front(), 1LL * nums1.back() * nums2.back()}) - 1;
        long long r = max({1LL * nums1.front() * nums2.front(), 1LL * nums1.front() * nums2.back(),
                           1LL * nums1.back() * nums2.front(), 1LL * nums1.back() * nums2.back()});
        
        while(l != r){
            long long mid = (l + r + 1) / 2;
            long long sumCount = 0;
            if(mid >= 0){
                sumCount = 1LL * pos1.size() * neg2.size() + 1LL * neg1.size() * pos2.size() +
                           countSumsLessOrEqual(pos1, pos2, mid) + countSumsLessOrEqual(neg1Rev, neg2Rev, mid);
            }else{
                sumCount = countSumsLessOrEqual(pos1Rev, neg2, mid) + countSumsLessOrEqual(neg1, pos2Rev, mid);
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