class Solution {
private:
    const int INF = 1e8;

    int getFirstNum(vector<int>& nums){
        if(nums.empty()){
            return INF;
        }
        return nums.front();
    }

    int getLastNum(vector<int>& nums){
        if(nums.empty()){
            return -INF;
        }
        return nums.back();
    }

    int countLessThanOrEqualTo(vector<int>& nums, const int NUM_THRESHOLD){
        return upper_bound(nums.begin(), nums.end(), NUM_THRESHOLD) - nums.begin();
    }

    int kthElementOfSortedArrays(vector<int>& nums1, vector<int>& nums2, int k){
        int l = min(getFirstNum(nums1), getFirstNum(nums2));
        int r = max(getLastNum(nums1), getLastNum(nums2));
        while(l != r){
            int mid = (l + r) / 2;
            if(2 * mid > l + r){
                mid -= 1;
            }
            if(countLessThanOrEqualTo(nums1, mid) +
               countLessThanOrEqualTo(nums2, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        return (kthElementOfSortedArrays(nums1, nums2, (N1 + N2 + 1) / 2) +
                kthElementOfSortedArrays(nums1, nums2, (N1 + N2 + 2) / 2)) / 2.0;
    }
};