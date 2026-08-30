class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> res;
        res.reserve(sortedNums.back() - sortedNums.front() + 1 - N);

        for(int i = 0; i + 1 < N; ++i){
            for(int num = sortedNums[i] + 1; num < sortedNums[i + 1]; ++num){
                res.push_back(num);
            }
        }

        return res;
    }
};