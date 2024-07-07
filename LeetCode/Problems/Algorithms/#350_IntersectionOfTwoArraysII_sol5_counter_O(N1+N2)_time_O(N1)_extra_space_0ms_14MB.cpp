class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        unordered_map<int, int> freq1;
        for(int num: nums1){
            freq1[num] += 1;
        }

        vector<int> intersection;
        for(int num: nums2){
            if(freq1.count(num) && freq1[num] >= 1){
                freq1[num] -= 1;
                intersection.push_back(num);
            }
        }

        return intersection;
    }
};