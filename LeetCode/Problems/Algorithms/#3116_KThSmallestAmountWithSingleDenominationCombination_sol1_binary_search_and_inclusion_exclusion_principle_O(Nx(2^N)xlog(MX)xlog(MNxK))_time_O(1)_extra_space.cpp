class Solution {
private:
    long long countAmounts(vector<int>& coins, long long threshold){
        const int N = coins.size();
        const int FULL_MASK = (1 << N) - 1;

        long long amounts = 0;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            long long currLCM = 0;
            for(int bit = 0; bit < N && currLCM <= threshold; ++bit){
                if((mask >> bit) & 1){
                    if(currLCM == 0){
                        currLCM = coins[bit];
                    }else{
                        currLCM = lcm(currLCM, coins[bit]);
                    }
                }
            }

            if(popcount((unsigned int)mask) % 2 == 0){
                amounts -= (threshold / currLCM);
            }else{
                amounts += (threshold / currLCM);
            }
        }

        return amounts;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        const long long MIN_COIN = *min_element(coins.begin(), coins.end());

        long long l = 1;
        long long r = MIN_COIN * k;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countAmounts(coins, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        return r;
    }
};