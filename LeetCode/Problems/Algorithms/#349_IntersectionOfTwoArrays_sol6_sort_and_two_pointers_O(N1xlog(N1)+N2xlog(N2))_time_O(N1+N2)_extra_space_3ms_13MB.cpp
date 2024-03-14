class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<int> sortedNums1 = nums1;
        vector<int> sortedNums2 = nums2;

        sort(sortedNums1.begin(), sortedNums1.end());
        sort(sortedNums2.begin(), sortedNums2.end());

        int i1 = 0;
        int i2 = 0;
        vector<int> intersection;
        while(i1 < N1 && i2 < N2){
            if(sortedNums1[i1] < sortedNums2[i2]){
                i1 += 1;
            }else if(sortedNums1[i1] > sortedNums2[i2]){
                i2 += 1;
            }else{
                if(intersection.empty() || intersection.back() != sortedNums1[i1]){
                    intersection.push_back(sortedNums1[i1]);
                }
                i1 += 1;
                i2 += 1;
            }
        }

        return intersection;
    }
};