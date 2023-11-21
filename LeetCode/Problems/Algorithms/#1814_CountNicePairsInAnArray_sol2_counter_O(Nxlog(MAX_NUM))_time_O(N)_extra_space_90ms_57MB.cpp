class Solution {
private:
    int computeRev(int num){
        int revNum = 0;
        while(num > 0){
            revNum = revNum * 10 + (num % 10);
            num /= 10;
        }
        return revNum;
    }

public:
    int countNicePairs(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;

        int nicePairs = 0;
        unordered_map<int, int> diffCount;
        for(int num: nums){
            int diff = num - computeRev(num);
            nicePairs += diffCount[diff];
            nicePairs %= MODULO;
            diffCount[diff] += 1;
        }

        return nicePairs;
    }
};