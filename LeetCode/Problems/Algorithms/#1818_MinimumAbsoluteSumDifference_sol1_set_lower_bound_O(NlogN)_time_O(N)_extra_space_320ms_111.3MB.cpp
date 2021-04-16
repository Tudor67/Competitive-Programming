class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        const int MODULO = 1e9 + 7;
        
        long long diff = 0;
        for(int i = 0; i < N; ++i){
            diff += abs(nums1[i] - nums2[i]);
        }
        
        long long answer = diff;
        set<int> nums1Set(nums1.begin(), nums1.end());
        for(int i = 0; i < N; ++i){
            set<int>::iterator it = nums1Set.lower_bound(nums2[i]);
            if(it != nums1Set.end()){
                long long currentDiff = diff - abs(nums1[i] - nums2[i]) + abs(*it - nums2[i]);
                answer = min(currentDiff, answer);
            }
            if(it != nums1Set.begin()){
                long long currentDiff = diff - abs(nums1[i] - nums2[i]) + abs(*prev(it) - nums2[i]);
                answer = min(currentDiff, answer);
            }
        }
        
        return answer % MODULO;
    }
};