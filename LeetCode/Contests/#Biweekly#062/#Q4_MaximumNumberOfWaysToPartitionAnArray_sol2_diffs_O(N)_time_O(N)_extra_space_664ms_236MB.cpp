class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);
        
        long long prefSum = 0;
        long long suffSum = TOTAL_SUM;
        unordered_map<long long, int> diffCount;
        for(int i = 1; i < N; ++i){
            prefSum += nums[i - 1];
            suffSum -= nums[i - 1];
            diffCount[prefSum - suffSum] += 1;
        }
        
        int answer = diffCount[0];
        prefSum = 0;
        suffSum = TOTAL_SUM;
        unordered_map<long long, int> prefDiffCount;
        unordered_map<long long, int>& suffDiffCount = diffCount;
        for(int i = 0; i < N; ++i){
            int d = k - nums[i];
            int ways = 0;
            if(prefDiffCount.count(d)){
                ways += prefDiffCount[d];
            }
            if(suffDiffCount.count(-d)){
                ways += suffDiffCount[-d];
            }
            answer = max(answer, ways);
            prefSum += nums[i];
            suffSum -= nums[i];
            prefDiffCount[prefSum - suffSum] += 1;
            suffDiffCount[prefSum - suffSum] -= 1;
        }
        
        return answer;
    }
};