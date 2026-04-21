class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        int maxDist = 0;
        for(int i = 0, j = 0; i < N1; ++i){
            j = max(j, i);
            while(j < N2 && nums1[i] <= nums2[j]){
                maxDist = max(maxDist, j - i);
                ++j;
            }
        }

        return maxDist;
    }
};