class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        int p1 = nums[0];
        int p2 = fast;
        while(p1 != p2){
            p1 = nums[p1];
            p2 = nums[p2];
        }

        return p1;
    }
};