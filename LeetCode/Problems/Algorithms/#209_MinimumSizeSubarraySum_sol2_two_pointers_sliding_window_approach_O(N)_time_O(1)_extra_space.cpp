class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int answer = INT_MAX;
        
        for(int i = 0, j = 0, sum = 0; j < nums.size(); ++j){
            sum += nums[j];
            while(sum >= s){
                answer = min(j - i + 1, answer);
                sum -= nums[i];
                i += 1;
            }
        }
        
        if(answer == INT_MAX){
            answer = 0;
        }
        
        return answer;
    }
};