class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = (int)nums.size() - 1;
        while(r - l + 1 >= 3){
            int mid = l + (r - l) / 2;
            int pos1 = (mid % 2 == 0 ? mid : mid - 1);
            int pos2 = (mid % 2 == 0 ? mid + 1 : mid);
            if(nums[pos1] == nums[pos2]){
                l = pos2 + 1;
            }else{
                r = pos2;
            }
        }
        
        int answer = (l % 2 == 0 ? nums[l] : nums[r]);
        return answer;
    }
};