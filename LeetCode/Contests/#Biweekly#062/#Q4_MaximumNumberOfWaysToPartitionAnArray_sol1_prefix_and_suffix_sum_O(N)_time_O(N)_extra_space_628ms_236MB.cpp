class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);
        
        long long suffSum = 0;
        unordered_map<long long, int> suffCount;
        for(int i = N - 1; i >= 0; --i){
            suffSum += nums[i];
            suffCount[suffSum] += 1;
        }
        
        int answer = 0;
        if(TOTAL_SUM % 2 == 0){
            suffCount[TOTAL_SUM] -= 1;
            answer = suffCount[TOTAL_SUM / 2];
            suffCount[TOTAL_SUM] += 1;
        }
        
        long long prefSum = 0;
        unordered_map<long long, int> prefCount;
        for(int i = 0; i < N; ++i){
            suffCount[suffSum] -= 1;
            suffSum -= nums[i];
            long long sum = TOTAL_SUM - nums[i] + k;
            if(sum % 2 == 0){
                int ways = 0;
                if(prefCount.count(sum / 2)){
                    ways += prefCount[sum / 2];
                }
                if(suffCount.count(sum / 2)){
                    ways += suffCount[sum / 2];
                }
                answer = max(answer, ways);
            }
            prefSum += nums[i];
            prefCount[prefSum] += 1;
        }
        
        return answer;
    }
};