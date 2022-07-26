class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int N = nums1.size();
        
        vector<int> diffs(N);
        for(int i = 0; i < N; ++i){
            diffs[i] = abs(nums1[i] - nums2[i]);
        }
        
        sort(diffs.rbegin(), diffs.rend());
        
        long long k = k1 + k2;
        for(int i = 0; i < N; ++i){
            if(i == N - 1 || diffs[i] != diffs[i + 1]){
                long long w = i + 1;
                long long h = diffs[i];
                if(i + 1 < N){
                    h -= diffs[i + 1];
                }
                
                if(w * h <= k){
                    diffs[0] -= h;
                    k -= (w * h);
                }else{
                    diffs[0] -= (k / w);
                    if(k % w != 0){
                        diffs[i - (k % w) + 1] = diffs[0] - 1;
                    }
                    k = 0;
                    break;
                }
            }
        }
        
        long long res = 0;
        long long prefMin = diffs[0];
        for(int i = 0; i < N; ++i){
            prefMin = min(prefMin, (long long)diffs[i]);
            res += (prefMin * prefMin);
        }
        
        return res;
    }
};