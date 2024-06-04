class Solution {
private:
    int countMatches(const vector<int>& A, vector<int> B){
        const int A_SIZE = A.size();
        const int B_SIZE = B.size();

        sort(B.begin(), B.end());

        int matches = 0;
        for(int i = 0; i < A_SIZE; ++i){
            if(binary_search(B.begin(), B.end(), A[i])){
                matches += 1;
            }
        }

        return matches;
    }

public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        return {countMatches(nums1, nums2),
                countMatches(nums2, nums1)};
    }
};