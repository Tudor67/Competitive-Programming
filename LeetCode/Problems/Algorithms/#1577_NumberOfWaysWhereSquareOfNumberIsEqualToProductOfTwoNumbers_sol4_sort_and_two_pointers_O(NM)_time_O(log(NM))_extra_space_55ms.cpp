class Solution {
private:
    int countTriplets(vector<int>& nums1, vector<int>& nums2){
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        int triplets = 0;
        for(int num1: nums1){
            long long target = num1 * 1LL * num1;
            int j = 0;
            int k = N2 - 1;
            while(j < k){
                long long prod = nums2[j] * 1LL * nums2[k];
                if(prod < target){
                    j += 1;
                }else if(prod > target){
                    k -= 1;
                }else{
                    int l = 1;
                    while(j + l < k && nums2[j] == nums2[j + l]){
                        l += 1;
                    }
                    int r = 1;
                    while(k - r > j + l - 1 && nums2[k - r] == nums2[k]){
                        r += 1;
                    }
                    if(nums2[j] == nums2[k]){
                        triplets += (l + r) * (l + r - 1) / 2;
                    }else{
                        triplets += (l * r);
                    }
                    j += l;
                    k -= r;
                }
            }
        }
        
        return triplets;
    }
    
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return countTriplets(nums1, nums2) + countTriplets(nums2, nums1);
    }
};