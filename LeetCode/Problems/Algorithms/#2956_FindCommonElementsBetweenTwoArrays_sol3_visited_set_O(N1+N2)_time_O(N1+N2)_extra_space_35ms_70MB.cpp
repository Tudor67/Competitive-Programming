class Solution {
private:
    int countMatches(const vector<int>& A, const vector<int>& B){
        const int A_SIZE = A.size();
        const int B_SIZE = B.size();

        unordered_set<int> bSet(B.begin(), B.end());

        int matches = 0;
        for(int i = 0; i < A_SIZE; ++i){
            if(bSet.count(A[i])){
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