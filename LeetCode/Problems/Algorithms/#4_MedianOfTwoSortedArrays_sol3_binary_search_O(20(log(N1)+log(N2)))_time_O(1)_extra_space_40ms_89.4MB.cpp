class Solution {
private:
    int countLess(const vector<int>& NUMS1, const vector<int>& NUMS2, const int& VAL){
        int count1 = lower_bound(NUMS1.begin(), NUMS1.end(), VAL) - NUMS1.begin();
        int count2 = lower_bound(NUMS2.begin(), NUMS2.end(), VAL) - NUMS2.begin();
        return count1 + count2;
    }
    
    int binarySearch(const vector<int>& NUMS1, const vector<int>& NUMS2, const int& COUNT_THRESHOLD){
        int l = -1e6;
        int r =  1e6;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(countLess(NUMS1, NUMS2, mid) <= COUNT_THRESHOLD){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        double median = (binarySearch(nums1, nums2, (N1 + N2 - 1) / 2) + binarySearch(nums1, nums2, (N1 + N2) / 2)) / 2.0;
        return median;
    }
};