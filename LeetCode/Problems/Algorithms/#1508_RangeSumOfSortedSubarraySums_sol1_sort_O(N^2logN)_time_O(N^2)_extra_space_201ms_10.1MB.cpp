class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        int sums[N * (N + 1) / 2];
        int idx = -1;
        for(int i = 0; i < N; ++i){
            int sum = 0;
            for(int j = i; j < N; ++j){
                sum += nums[j];
                sums[++idx] = sum;
            }
        }
        
        sort(sums, sums + N * (N + 1) / 2);
        
        int answer = 0;
        for(int i = left - 1; i <= right - 1; ++i){
            answer += sums[i];
            answer %= MODULO;
        }
        
        return answer;
    }
};