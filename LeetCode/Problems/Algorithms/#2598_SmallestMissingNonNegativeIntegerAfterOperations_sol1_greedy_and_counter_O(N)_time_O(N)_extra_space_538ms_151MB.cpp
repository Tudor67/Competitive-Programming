class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int num: nums){
            int rem = ((num % value) + value) % value;
            count[rem] += 1;
        }
        
        for(int num = 0; num <= N; ++num){
            if(count[num] >= 1){
                count[num + value] += (count[num] - 1);
                count.erase(num);
            }else{
                return num;
            }
        }
        
        return -1;
    }
};