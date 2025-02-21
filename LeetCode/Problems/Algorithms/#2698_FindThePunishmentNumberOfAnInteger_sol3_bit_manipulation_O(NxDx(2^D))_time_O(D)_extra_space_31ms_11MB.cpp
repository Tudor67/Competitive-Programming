class Solution {
private:
    bool canBePartitioned(int num, int targetSum){
        const string NUM_STR = to_string(num);
        const int NUM_STR_LEN = NUM_STR.length();
        const int FULL_MASK = (1 << NUM_STR_LEN) - 1;

        for(int mask = 0; mask <= FULL_MASK; ++mask){
            if(!((mask >> (NUM_STR_LEN - 1)) & 1)){
                continue;
            }

            int sum = 0;
            int x = 0;
            for(int bit = 0; bit < NUM_STR_LEN; ++bit){
                x = x * 10 + (NUM_STR[bit] - '0');
                if((mask >> bit) & 1){
                    sum += x;
                    x = 0;
                }
            }

            if(sum == targetSum){
                return true;
            }
        }

        return false;
    }

public:
    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i){
            if(canBePartitioned(i * i, i)){
                res += i * i;
            }
        }
        return res;
    }
};