class Solution {
private:
    int countTriplets(vector<int>& nums1, vector<int>& nums2){
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        unordered_map<long long, int> sqCount;
        for(int num: nums1){
            sqCount[num * 1LL * num] += 1;
        }
        
        int triplets = 0;
        for(int j = 0; j < N2; ++j){
            for(int k = j + 1; k < N2; ++k){
                long long prod = nums2[j] * 1LL * nums2[k];
                if(sqCount.count(prod)){
                    triplets += sqCount[prod];
                }
            }
        }
        
        return triplets;
    }
    
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return countTriplets(nums1, nums2) + countTriplets(nums2, nums1);
    }
};