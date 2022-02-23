class Solution {
private:
    int countTriplets(vector<int>& nums1, vector<int>& nums2){
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        int triplets = 0;
        unordered_map<int, int> count;
        for(int num1: nums1){
            long long target = num1 * 1LL * num1;
            count.clear();
            for(int num2: nums2){
                if(target % num2 == 0 && count.count(target / num2)){
                    triplets += count[target / num2];
                }
                count[num2] += 1;
            }
        }
        
        return triplets;
    }
    
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return countTriplets(nums1, nums2) + countTriplets(nums2, nums1);
    }
};