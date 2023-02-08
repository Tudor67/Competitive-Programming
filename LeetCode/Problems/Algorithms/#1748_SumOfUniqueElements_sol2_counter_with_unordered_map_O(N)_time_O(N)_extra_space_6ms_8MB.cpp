class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        int sum = 0;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;
            if(numCount == 1){
                sum += num;
            }
        }

        return sum;
    }
};