class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        const int MODULO = 1e9 + 7;
        
        int diff = 0;
        for(int i = 0; i < N; ++i){
            diff += abs(nums1[i] - nums2[i]);
            diff %= MODULO;
        }
        
        int maxChange = 0;
        set<int> nums1Set(nums1.begin(), nums1.end());
        for(int i = 0; i < N; ++i){
            set<int>::iterator it = nums1Set.lower_bound(nums2[i]);
            if(it != nums1Set.end()){
                maxChange = max(abs(nums1[i] - nums2[i]) - abs(*it - nums2[i]), maxChange);
            }
            if(it != nums1Set.begin()){
                maxChange = max(abs(nums1[i] - nums2[i]) - abs(*prev(it) - nums2[i]), maxChange);
            }
        }
        
        return (diff - maxChange + MODULO) % MODULO;
    }
};