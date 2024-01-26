class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for(int i = 0; i < N - 1; ++i){
            if(sortedNums[i] != i + 1){
                return false;
            }
        }

        return (sortedNums[N - 1] == N - 1);
    }
};