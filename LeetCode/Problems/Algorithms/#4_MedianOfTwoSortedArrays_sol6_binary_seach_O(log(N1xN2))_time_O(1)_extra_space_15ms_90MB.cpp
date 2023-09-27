class Solution {
private:
    int kthElementInSortedArrays(vector<int>& nums1, vector<int>& nums2, int k){
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        if(N1 == 0){
            return nums2[k - 1];
        }
        
        if(N2 == 0){
            return nums1[k - 1];
        }

        if(k == 1){
            return min(nums1.front(), nums2.front());
        }

        if(k == N1 + N2){
            return max(nums1.back(), nums2.back());
        }

        int l1 = 0;
        int r1 = N1 - 1;
        int l2 = 0;
        int r2 = N2 - 1;
        while(l1 != r1 && l2 != r2){
            int mid1 = (l1 + r1) / 2;
            int mid2 = (l2 + r2) / 2;
            if(mid1 + mid2 + 2 < k){
                if(nums1[mid1] <= nums2[mid2]){
                    l1 = mid1 + 1;
                }else{
                    l2 = mid2 + 1;
                }
            }else{
                if(nums1[mid1] <= nums2[mid2]){
                    r2 = mid2;
                }else{
                    r1 = mid1;
                }
            }
        }

        if(l1 == r1){
            int x1 = nums1[r1];
            int x2 = nums2[k - (r1 + 1) - 1];
            int x3 = (r1 == 0 ? INT_MIN : nums1[r1 - 1]);
            int x4 = nums2[k - (r1 - 1 + 1) - 1];
            return min(max(x1, x2), max(x3, x4));
        }
        int x1 = nums1[k - (r2 + 1) - 1];
        int x2 = nums2[r2];
        int x3 = nums1[k - (r2 - 1 + 1) - 1];
        int x4 = (r2 == 0 ? INT_MIN : nums2[r2 - 1]);
        return min(max(x1, x2), max(x3, x4));
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        return (kthElementInSortedArrays(nums1, nums2, (N1 + N2 + 1) / 2) +
                kthElementInSortedArrays(nums1, nums2, (N1 + N2 + 2) / 2)) / 2.0;
    }
};