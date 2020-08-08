class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        
        for(int i = 0; i < nums.size(); ++i){
            int val = abs(nums[i]);
            int pos = val - 1;
            bool is_duplicate = (nums[pos] < 0);
            
            if(is_duplicate){
                answer.push_back(val);
            }else{
                nums[pos] = -nums[pos];
            }
        }
        
        return answer;
    }
};