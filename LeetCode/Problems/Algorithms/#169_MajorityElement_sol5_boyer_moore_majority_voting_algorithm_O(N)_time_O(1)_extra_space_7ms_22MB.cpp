class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int candidateVotes = 0;
        for(int num: nums){
            if(candidateVotes == 0){
                candidate = num;
                candidateVotes = 1;
            }else if(candidate == num){
                candidateVotes += 1;
            }else{
                candidateVotes -= 1;
            }
        }
        return candidate;
    }
};