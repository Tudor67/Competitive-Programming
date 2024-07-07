class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<int> sortedNums1 = nums1;
        sort(sortedNums1.begin(), sortedNums1.end());

        vector<int> sortedNums2 = nums2;
        sort(sortedNums2.begin(), sortedNums2.end());

        vector<int> intersection;
        int i1 = 0;
        for(int num: sortedNums2){
            while(i1 < N1 && sortedNums1[i1] < num){
                i1 += 1;
            }
            if(i1 < N1 && sortedNums1[i1] == num){
                i1 += 1;
                intersection.push_back(num);
            }
        }

        return intersection;
    }
};