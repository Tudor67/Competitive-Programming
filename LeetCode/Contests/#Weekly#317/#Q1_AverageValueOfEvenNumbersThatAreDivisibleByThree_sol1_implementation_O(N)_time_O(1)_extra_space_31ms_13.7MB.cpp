class Solution {
public:
    int averageValue(vector<int>& nums) {
        const int N = nums.size();
        
        int sum = 0;
        int count = 0;
        for(int num: nums){
            if(num % 6 == 0){
                sum += num;
                count += 1;
            }
        }
        
        if(count == 0){
            return 0;
        }
        
        return sum / count;
    }
};