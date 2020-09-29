class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int candidate2 = 0;
        int frequency1 = 0;
        int frequency2 = 0;
        
        for(int num: nums){
            if(candidate1 == num){
                frequency1 += 1;
            }else if(candidate2 == num){
                frequency2 += 1;
            }else if(frequency1 == 0){
                candidate1 = num;
                frequency1 = 1;
            }else if(frequency2 == 0){
                candidate2 = num;
                frequency2 = 1;
            }else{
                frequency1 -= 1;
                frequency2 -= 1;
            }
        }
        
        frequency1 = 0;
        frequency2 = 0;
        for(int num: nums){
            frequency1 += (num == candidate1);
            frequency2 += (num == candidate2);
        }
        
        bool isValid1 = (frequency1 > nums.size() / 3);
        bool isValid2 = (frequency2 > nums.size() / 3 && candidate1 != candidate2);
        
        vector<int> answer;
        if(isValid1){
            answer.push_back(candidate1);
        }
        if(isValid2){
            answer.push_back(candidate2);
        }
        
        return answer;
    }
};