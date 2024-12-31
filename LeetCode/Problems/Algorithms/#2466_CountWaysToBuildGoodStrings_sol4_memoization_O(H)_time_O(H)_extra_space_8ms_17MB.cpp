class Solution {
private:
    const int MODULO = 1'000'000'007;

    int countGoodStrings(int len, int zero, int one, vector<int>& memo){
        if(len < 0){
            return 0;
        }

        if(len == 0){
            return 1;
        }

        if(memo[len] == -1){
            memo[len] = (countGoodStrings(len - zero, zero, one, memo) +
                         countGoodStrings(len - one, zero, one, memo)) % MODULO;
        }

        return memo[len];
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int goodStrings = 0;
        vector<int> memo(high + 1, -1);
        for(int len = low; len <= high; ++len){
            goodStrings = (goodStrings + countGoodStrings(len, zero, one, memo)) % MODULO;
        }
        return goodStrings;
    }
};