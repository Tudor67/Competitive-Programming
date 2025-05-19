class Solution {
private:
    int f(int i, int minDiff, int len, vector<int>& sortedNums, const int MODULO, unordered_map<long long, int>& memo){
        if(len == 1){
            return minDiff;
        }

        long long state = i | (len << 7) | (((long long)minDiff) << 15);
        if(memo.count(state)){
            return memo[state];
        }

        int res = 0;
        for(int j = i - 1; j >= 0; --j){
            res += f(j, min(abs(sortedNums[i] - sortedNums[j]), minDiff), len - 1, sortedNums, MODULO, memo);
            res %= MODULO;
        }

        memo[state] = res;
        return res;
    }

public:
    int sumOfPowers(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int res = 0;
        unordered_map<long long, int> memo;
        for(int i = 0; i < N; ++i){
            res += f(i, INT_MAX, k, sortedNums, MODULO, memo);
            res %= MODULO;
        }
        
        return res;
    }
};