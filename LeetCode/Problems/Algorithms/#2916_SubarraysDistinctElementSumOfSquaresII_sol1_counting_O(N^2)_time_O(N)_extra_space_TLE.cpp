class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int N = nums.size();
        const long long MODULO = 1e9 + 7;

        long long res = 0;
        long long sum2 = 0;
        vector<int> distinctsFrom(N);
        unordered_map<int, int> lastIndexOf;

        for(int i = 0; i < N; ++i){
            if(!lastIndexOf.count(nums[i])){
                lastIndexOf[nums[i]] = -1;
            }
            
            int sum1 = 0;
            for(int j = lastIndexOf[nums[i]] + 1; j < i; ++j){
                sum1 += distinctsFrom[j];
                sum1 %= MODULO;
            }

            sum2 += 2 * sum1;
            sum2 += i - lastIndexOf[nums[i]] - 1;
            sum2 += 1;
            sum2 %= MODULO;

            res += sum2;
            res %= MODULO;

            for(int j = lastIndexOf[nums[i]] + 1; j <= i; ++j){
                distinctsFrom[j] += 1;
            }
            lastIndexOf[nums[i]] = i;
        }

        return res;
    }
};