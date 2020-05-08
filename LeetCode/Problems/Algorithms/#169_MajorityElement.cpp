class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int answer = nums[0];
        int cnt = 0;
        
        for(int num: nums){
            if(num == answer){
                ++cnt;
            }
            else if(cnt == 0){
                answer = num;
                cnt = 1;
            }
            else if(cnt > 0){
                --cnt;
            }
        }
        
        return answer;
    }
};