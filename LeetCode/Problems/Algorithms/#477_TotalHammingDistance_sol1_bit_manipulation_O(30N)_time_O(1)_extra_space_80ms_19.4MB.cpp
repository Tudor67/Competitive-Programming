class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int MAX_BIT = 29;
        int answer = 0;
        for(int bit = 0; bit <= MAX_BIT; ++bit){
            int ones = 0;
            int zeros = 0;
            for(int num: nums){
                int bitVal = (num >> bit) & 1;
                ones += (bitVal == 1);
                zeros += (bitVal == 0);
            }
            answer += ones * zeros;
        }
        return answer;
    }
};