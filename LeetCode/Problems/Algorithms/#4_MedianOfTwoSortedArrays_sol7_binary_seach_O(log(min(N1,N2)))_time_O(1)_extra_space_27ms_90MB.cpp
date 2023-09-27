class Solution {
private:
    const int INF = 1e9;

    int getVal(vector<int>& A, int index){
        if(index < 0){
            return -INF;
        }
        if(index >= (int)A.size()){
            return INF;
        }
        return A[index];
    }

    int kthElementOfSortedArrays(vector<int>& A, vector<int>& B, int k){
        if(A.size() > B.size()){
            return kthElementOfSortedArrays(B, A, k);
        }

        int l = 0;
        int r = A.size();
        while(true){
            int midA = (l + r) / 2;
            int midB = k - midA;

            int maxLeftA = getVal(A, midA - 1);
            int minRightA = getVal(A, midA);

            int maxLeftB = getVal(B, midB - 1);
            int minRightB = getVal(B, midB);

            if(maxLeftA <= minRightB && maxLeftB <= minRightA){
                return max(maxLeftA, maxLeftB);
            }else if(maxLeftB > minRightA){
                l = midA + 1;
            }else{
                r = midA;
            }
        }

        return INF;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        return (kthElementOfSortedArrays(nums1, nums2, (N1 + N2 + 1) / 2) +
                kthElementOfSortedArrays(nums1, nums2, (N1 + N2 + 2) / 2)) / 2.0;
    }
};