class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res(N);

        unordered_map<int, int> count;
        for(int i = 0; i < N; ++i){
            count[nums[i]] += 1;
            res[i] += (int)count.size();
        }

        count.clear();
        for(int i = N - 1; i >= 0; --i){
            res[i] -= (int)count.size();
            count[nums[i]] += 1;
        }
        
        return res;
    }
};