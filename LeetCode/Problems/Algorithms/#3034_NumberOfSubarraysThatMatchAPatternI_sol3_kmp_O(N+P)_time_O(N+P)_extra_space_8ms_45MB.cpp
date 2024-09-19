class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        const int N = nums.size();
        
        vector<int> v(N - 1, 0);
        for(int i = 0; i < (int)v.size(); ++i){
            if(nums[i] < nums[i + 1]){
                v[i] = 1;
            }else if(nums[i] > nums[i + 1]){
                v[i] = -1;
            }
        }

        vector<int> pv;
        copy(pattern.begin(), pattern.end(), back_inserter(pv));
        pv.push_back(INT_MIN);
        copy(v.begin(), v.end(), back_inserter(pv));

        vector<int> lps(pv.size());
        for(int i = 1; i < (int)pv.size(); ++i){
            int k = lps[i - 1];
            while(k > 0 && pv[k] != pv[i]){
                k = lps[k - 1];
            }
            if(pv[k] == pv[i]){
                k += 1;
            }
            lps[i] = k;
        }

        return count(lps.begin(), lps.end(), pattern.size());
    }
};