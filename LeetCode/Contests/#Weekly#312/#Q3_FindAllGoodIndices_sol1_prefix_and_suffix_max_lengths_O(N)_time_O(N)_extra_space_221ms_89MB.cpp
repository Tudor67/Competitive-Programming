class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> l(N, 1);
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] >= nums[i]){
                l[i] = l[i - 1] + 1;
            }
        }
        
        vector<int> r(N, 1);
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] <= nums[i + 1]){
                r[i] = r[i + 1] + 1;
            }
        }
        
        vector<int> res;
        for(int i = 1; i + 1 < N; ++i){
            if(l[i - 1] >= k && r[i + 1] >= k){
                res.push_back(i);
            }
        }
        
        return res;
    }
};