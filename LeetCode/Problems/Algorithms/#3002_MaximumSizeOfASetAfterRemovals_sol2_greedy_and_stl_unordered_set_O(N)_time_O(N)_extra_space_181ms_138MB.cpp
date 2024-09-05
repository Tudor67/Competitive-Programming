class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        unordered_set<int> intersection;
        for(int num: s1){
            if(s2.count(num)){
                intersection.insert(num);
            }
        }

        int contrib1 = 0;
        for(int num: s1){
            if(contrib1 < N / 2 && !intersection.count(num)){
                contrib1 += 1;
            }
        }

        int contrib2 = 0;
        for(int num: s2){
            if(contrib2 < N / 2 && !intersection.count(num)){
                contrib2 += 1;
            }
        }

        return min(N, contrib1 + contrib2 + (int)intersection.size());
    }
};