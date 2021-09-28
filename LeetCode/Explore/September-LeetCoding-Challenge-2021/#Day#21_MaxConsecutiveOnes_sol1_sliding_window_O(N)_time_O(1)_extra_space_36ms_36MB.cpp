class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveOnes = 0;
        int curConsecutiveOnes = 0;
        for(int num: nums){
            if(num == 1){
                curConsecutiveOnes += 1;
                maxConsecutiveOnes = max(maxConsecutiveOnes, curConsecutiveOnes);
            }else{
                curConsecutiveOnes = 0;
            }
        }
        return maxConsecutiveOnes;
    }
};