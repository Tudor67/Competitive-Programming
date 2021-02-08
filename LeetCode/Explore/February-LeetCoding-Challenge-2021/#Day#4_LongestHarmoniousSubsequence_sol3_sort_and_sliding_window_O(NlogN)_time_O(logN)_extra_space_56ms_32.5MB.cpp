class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        int prevPos = 0;
        for(int pos = 0; pos < nums.size(); ++pos){
            if(nums[prevPos] + 1 == nums[pos]){
                answer = max(pos - prevPos + 1, answer);
            }else{
                while(prevPos < pos && nums[prevPos] + 1 < nums[pos]){
                    prevPos += 1;
                }
            }
        }
        
        return answer;
    }
};