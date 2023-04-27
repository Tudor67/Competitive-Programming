class Solution {
public:
    int maxScore(vector<int>& nums) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.rbegin(), sortedNums.rend());

        int res = 0;
        long long prefSum = 0;
        for(int num: sortedNums){
            prefSum += num;
            if(prefSum > 0){
                res += 1;
            }
        }

        return res;
    }
};