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

        vector<int> z(pv.size());
        int l = 0;
        int r = 0;
        for(int i = 1; i < (int)pv.size(); ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < (int)pv.size() && pv[z[i]] == pv[i + z[i]]){
                z[i] += 1;
            }
            if(r <= i + z[i] - 1){
                l = i;
                r = i + z[i] - 1;
            }
        }

        return count(z.begin(), z.end(), pattern.size());
    }
};