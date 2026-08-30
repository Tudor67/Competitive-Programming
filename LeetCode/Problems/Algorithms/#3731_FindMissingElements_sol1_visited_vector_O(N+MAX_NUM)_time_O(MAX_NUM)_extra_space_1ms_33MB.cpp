class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<bool> vis(MAX_NUM + 1);
        for(int num: nums){
            vis[num] = true;
        }

        vector<int> res;
        for(int num = MIN_NUM + 1; num <= MAX_NUM - 1; ++num){
            if(!vis[num]){
                res.push_back(num);
            }
        }

        return res;
    }
};