class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        
        unordered_map<int, int> posOf;
        posOf[0] = N;
        int sufSum = 0;
        for(int i = N - 1; i >= 0; --i){
            sufSum += nums[i];
            posOf[sufSum] = i;
        }
        
        int answer = INT_MAX;
        int prefSum = 0;
        for(int i = -1; i < N; ++i){
            prefSum += (i == -1 ? 0 : nums[i]);
            if(posOf.count(x - prefSum) && i < posOf[x - prefSum]){
                answer = min(i + 1 + N - posOf[x - prefSum], answer);
            }
        }
        
        if(answer == INT_MAX){
            answer = -1;
        }
        
        return answer;
    }
};