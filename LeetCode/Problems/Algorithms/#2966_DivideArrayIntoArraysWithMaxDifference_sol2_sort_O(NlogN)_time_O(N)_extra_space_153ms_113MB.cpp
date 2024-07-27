class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<vector<int>> res;
        res.reserve(N / 3);
        for(int i = 2; i < N; i += 3){
            if(sortedNums[i] - sortedNums[i - 2] <= k){
                res.push_back({sortedNums[i - 2], sortedNums[i - 1], sortedNums[i]});
            }else{
                res.clear();
                break;
            }
        }

        return res;
    }
};