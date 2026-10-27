class Solution {
private:
    long long computeMinModifications(vector<int>& nums1, vector<int>& nums2, int diffThreshold){
        const int N = nums1.size();
        long long minModifications = 0;
        for(int i = 0; i < N; ++i){
            int diff = abs(nums1[i] - nums2[i]);
            minModifications += max(0, diff - diffThreshold);
        }
        return minModifications;
    }

public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int N = nums1.size();
        
        int maxDiff = 0;
        for(int i = 0; i < N; ++i){
            maxDiff = max(maxDiff, abs(nums1[i] - nums2[i]));
        }

        int l = 0;
        int r = maxDiff;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeMinModifications(nums1, nums2, mid) > k1 + k2){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        long long res = 0;
        int diffThreshold = r;
        long long remOps = k1 + k2 - computeMinModifications(nums1, nums2, diffThreshold);

        for(int i = 0; i < N; ++i){
            int diff = min(abs(nums1[i] - nums2[i]), diffThreshold);
            if(diff == diffThreshold && remOps >= 1){
                remOps -= 1;
                diff = max(0, diff - 1);
            }
            res += ((long long)diff * (long long)diff);
        }
        
        return res;
    }
};