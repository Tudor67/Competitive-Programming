class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        unordered_map<int, int> freq1;
        for(int num: nums1){
            freq1[num] += 1;
        }

        unordered_map<int, int> freq2;
        for(int num: nums2){
            freq2[num] += 1;
        }

        vector<int> answer(2);
        for(const pair<const int, int>& P: freq1){
            int num = P.first;
            if(freq2.count(num)){
                answer[0] += freq1[num];
                answer[1] += freq2[num];
            }
        }

        return answer;
    }
};