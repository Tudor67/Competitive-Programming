class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int FULL_MASK = (1 << N) - 1;

        int res = 0;
        vector<bool> vis(MAX_NUM + 1);

        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                vis[nums[bit]] = false;
            }

            bool isValid = true;
            for(int bit = 0; bit < N && isValid; ++bit){
                if((mask >> bit) & 1){
                    if((nums[bit] >= k && vis[nums[bit] - k]) ||
                       (nums[bit] + k <= MAX_NUM && vis[nums[bit] + k])){
                        isValid = false;
                    }
                    vis[nums[bit]] = true;
                }
            }

            if(isValid){
                res += 1;
            }
        }

        return res;
    }
};