class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        int intersectionSize = 0;
        for(int num: s1){
            if(s2.count(num)){
                intersectionSize += 1;
            }
        }

        int contrib1 = min(N / 2, (int)s1.size() - intersectionSize);
        int contrib2 = min(N / 2, (int)s2.size() - intersectionSize);

        return min(N, contrib1 + contrib2 + intersectionSize);
    }
};