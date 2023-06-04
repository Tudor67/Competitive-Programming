class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> count(N + 1);
        for(int num: nums){
            count[num] += 1;
        }

        int maxCount = *max_element(count.begin(), count.end());
        vector<vector<int>> res(maxCount);
        for(int num = 0; num <= N; ++num){
            for(int c = 0; c < count[num]; ++c){
                res[c].push_back(num);
            }
        }
        
        return res;
    }
};