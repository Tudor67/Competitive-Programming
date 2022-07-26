class Solution {
private:
    long long countOperations(vector<int>& nums1, vector<int>& nums2, const long long& MAX_DIFF_THRESHOLD){
        const int N = nums1.size();
        long long operations = 0;
        for(int i = 0; i < N; ++i){
            long long diff = abs(nums1[i] - nums2[i]);
            if(diff >= MAX_DIFF_THRESHOLD){
                operations += (diff - MAX_DIFF_THRESHOLD);
            }
        }
        return operations;
    }
    
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int N = nums1.size();
        
        int maxDiff = abs(nums1[0] - nums2[0]);
        for(int i = 0; i < N; ++i){
            int diff = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff);
        }
        
        // binary search min threshold such that: countOperations(nums1, nums2, threshold) <= k1 + k2
        // countOperations(nums1, nums2, threshold) computes the number of operations to make all the differences
        //                                          between nums1 and nums2 (i.e., abs(nums1[i] - nums2[i]))
        //                                          less than or equal to threshold
        int l = 0;
        int r = maxDiff;
        while(l != r){
            int mid = (l + r) / 2;
            if(countOperations(nums1, nums2, mid) <= k1 + k2){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        const long long MAX_DIFF_THRESHOLD = r;
        long long rem = k1 + k2 - countOperations(nums1, nums2, MAX_DIFF_THRESHOLD);
        long long res = 0;
        for(int i = 0; i < N; ++i){
            long long diff = abs(nums1[i] - nums2[i]);
            if(diff >= MAX_DIFF_THRESHOLD){
                diff = MAX_DIFF_THRESHOLD;
            }
            if(diff == MAX_DIFF_THRESHOLD && diff > 0 && rem > 0){
                diff -= 1;
                rem -= 1;
            }
            res += (diff * diff);
        }
        
        return res;
    }
};