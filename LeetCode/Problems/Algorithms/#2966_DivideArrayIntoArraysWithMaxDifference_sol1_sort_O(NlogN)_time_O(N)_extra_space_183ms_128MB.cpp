class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<vector<int>> res(N / 3);
        for(int i = 0; i < N; i += 3){
            if(sortedNums[i + 2] - sortedNums[i] <= k){
                copy(sortedNums.begin() + i, sortedNums.begin() + i + 3, back_inserter(res[i / 3]));
            }else{
                return {};
            }
        }

        return res;
    }
};