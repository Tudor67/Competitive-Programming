class Solution {
private:
    int getMinValFromSortedArrays(const vector<int>& NUMS1, const vector<int>& NUMS2){
        if(NUMS1.empty()){
            return NUMS2.front();
        }
        if(NUMS2.empty()){
            return NUMS1.front();
        }
        return min(NUMS1.front(), NUMS2.front());
    }
    
    int getMaxValFromSortedArrays(const vector<int>& NUMS1, const vector<int>& NUMS2){
        if(NUMS1.empty()){
            return NUMS2.back();
        }
        if(NUMS2.empty()){
            return NUMS1.back();
        }
        return max(NUMS1.back(), NUMS2.back());
    }
    
    int countLess(const vector<int>& NUMS1, const vector<int>& NUMS2, const int& VAL){
        int count1 = lower_bound(NUMS1.begin(), NUMS1.end(), VAL) - NUMS1.begin();
        int count2 = lower_bound(NUMS2.begin(), NUMS2.end(), VAL) - NUMS2.begin();
        return count1 + count2;
    }
    
    int binarySearch(const vector<int>& NUMS1, const vector<int>& NUMS2, const int& COUNT_THRESHOLD, const int& L, const int& R){
        int l = L;
        int r = R;
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
        const int MIN_VAL = getMinValFromSortedArrays(nums1, nums2);
        const int MAX_VAL = getMaxValFromSortedArrays(nums1, nums2);
        double median = (binarySearch(nums1, nums2, (N1 + N2 - 1) / 2, MIN_VAL, MAX_VAL) +
                         binarySearch(nums1, nums2, (N1 + N2) / 2, MIN_VAL, MAX_VAL)) / 2.0;
        return median;
    }
};