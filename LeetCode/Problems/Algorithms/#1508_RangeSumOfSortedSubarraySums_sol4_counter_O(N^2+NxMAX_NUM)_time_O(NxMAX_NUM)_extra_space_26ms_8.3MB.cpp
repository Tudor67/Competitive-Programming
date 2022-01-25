class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MAX_SUM = N * MAX_NUM;
        const int MODULO = 1e9 + 7;
        
        int count[MAX_SUM + 1];
        fill(count, count + MAX_SUM + 1, 0);
        
        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(int j = i; j < N; ++j){
                sum += nums[j];
                count[sum] += 1;
            }
        }
        
        int answer = 0;
        int need = right - left + 1;
        int prefCount = 0;
        for(int sum = 1; sum <= MAX_SUM; ++sum){
            prefCount += count[sum];
            if(prefCount >= left && need > 0){
                int toExtract = min(count[sum], prefCount - left + 1);
                while(toExtract > 0 && need > 0){
                    answer += sum;
                    answer %= MODULO;
                    toExtract -= 1;
                    need -= 1;
                }
            }
        }
        
        return answer;
    }
};