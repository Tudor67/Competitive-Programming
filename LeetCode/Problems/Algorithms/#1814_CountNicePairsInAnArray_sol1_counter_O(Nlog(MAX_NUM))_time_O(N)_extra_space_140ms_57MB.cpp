class Solution {
private:
    int rev(int x){
        int xRev = 0;
        while(x > 0){
            xRev = xRev * 10 + (x % 10);
            x /= 10;
        }
        return xRev;
    }

public:
    int countNicePairs(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;

        int res = 0;
        unordered_map<int, int> count;
        for(int num: nums){
            int diff = num - rev(num);
            res = (res + count[diff]) % MODULO;
            count[diff] += 1;
        }

        return res;
    }
};