class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        int maxMatch = 0;
        for(int startPos = -(N2 - 1); startPos < N1; ++startPos){
            int match = 0;
            for(int i1 = startPos, i2 = 0; i1 < N1 && i2 < N2; ++i1, ++i2){
                if(i1 >= 0 && i2 >= 0 && nums1[i1] == nums2[i2]){
                    match += 1;
                    maxMatch = max(maxMatch, match);
                }else{
                    match = 0;
                }
            }
        }
        
        return maxMatch;
    }
};