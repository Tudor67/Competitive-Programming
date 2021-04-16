class Solution {
private:
    int countLessOrEqual(const vector<int>& NUMS1, const vector<int>& NUMS2, const int& VAL){
        int count1 = upper_bound(NUMS1.begin(), NUMS1.end(), VAL) - NUMS1.begin();
        int count2 = upper_bound(NUMS2.begin(), NUMS2.end(), VAL) - NUMS2.begin();
        return count1 + count2;
    }
    
    int binarySearch(const vector<int>& NUMS1, const vector<int>& NUMS2, const int& COUNT_THRESHOLD){
        int l = 0;
        int r = 2e6;
        while(l != r){
            int mid = (l + r) / 2;
            if(countLessOrEqual(NUMS1, NUMS2, mid - 1e6) <= COUNT_THRESHOLD){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r - 1e6;
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        double median = (binarySearch(nums1, nums2, (N1 + N2 - 1) / 2) + binarySearch(nums1, nums2, (N1 + N2) / 2)) / 2.0;
        return median;
    }
};