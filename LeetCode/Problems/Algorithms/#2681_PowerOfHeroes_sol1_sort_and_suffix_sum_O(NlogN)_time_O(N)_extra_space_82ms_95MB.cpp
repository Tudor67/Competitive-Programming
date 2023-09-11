class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        const int N = nums.size();
        const long long MODULO = 1e9 + 7;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long res = 0;
        long long totalSuffSqrSum = 0;
        for(int i = N - 1; i >= 0; --i){
            long long num = sortedNums[i];
            long long sqrSum = (num * num + totalSuffSqrSum) % MODULO;
            res = (res + num * sqrSum) % MODULO;
            totalSuffSqrSum = (totalSuffSqrSum + sqrSum) % MODULO;
        }

        return res;
    }
};