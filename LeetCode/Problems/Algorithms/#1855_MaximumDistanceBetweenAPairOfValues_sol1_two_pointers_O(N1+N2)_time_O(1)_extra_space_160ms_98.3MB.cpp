class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        int maxDistance = 0;
        int j = 0;
        for(int i = 0; i < N1; ++i){
            j = max(i, j);
            while(j < N2 && nums1[i] <= nums2[j]){
                ++j;
            }
            maxDistance = max(j - i - 1, maxDistance);
        }
        
        return maxDistance;
    }
};