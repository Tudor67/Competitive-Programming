class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        int answer = INT_MAX;
        int prefSum = 0;
        int sufSum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = -1, j = 0; i < N; ++i){
            prefSum += (i <= -1 ? 0 : nums[i]);
            while(j < N && (prefSum + sufSum > x || i >= j)){
                sufSum -= nums[j];
                j += 1;
            }
            if(prefSum + sufSum == x){
                answer = min(i + 1 + N - j, answer);
            }
        }
        return (answer == INT_MAX ? -1 : answer);
    }
};