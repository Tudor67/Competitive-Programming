class Solution {
private:
    int computeReverseNumber(int num){
        int revNum = 0;
        while(num > 0){
            revNum = revNum * 10 + (num % 10);
            num /= 10;
        }
        return revNum;
    }
    
public:
    int countDistinctIntegers(vector<int>& nums) {
        const int N = nums.size();
        unordered_set<int> vis;
        for(int num: nums){
            vis.insert(num);
            vis.insert(computeReverseNumber(num));
        }
        return vis.size();
    }
};