class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const int MODULO = 1e9 + 7;
        const int P = hats.size();
        const int FULL_PEOPLE_MASK = (1 << P) - 1;
        const int MAX_HAT = 40;
        
        vector<vector<int>> prefHatsCount(P, vector<int>(MAX_HAT + 1, 0));
        for(int person = 0; person < P; ++person){
            for(int hat: hats[person]){
                prefHatsCount[person][hat] = 1;
            }
            for(int hat = 1; hat <= MAX_HAT; ++hat){
                prefHatsCount[person][hat] += prefHatsCount[person][hat - 1];
            }
        }
        
        vector<vector<int>> dp(FULL_PEOPLE_MASK + 1, vector<int>(MAX_HAT + 1, 0));
        for(int curMaxHat = 1; curMaxHat <= MAX_HAT; ++curMaxHat){
            for(int person = 0; person < P; ++person){
                int personMask = (1 << person);
                dp[personMask][curMaxHat] = prefHatsCount[person][curMaxHat];
            }
            for(int peopleMask = 1; peopleMask <= FULL_PEOPLE_MASK; ++peopleMask){
                if(__builtin_popcount(peopleMask) > 1){
                    int count = dp[peopleMask][curMaxHat - 1];
                    for(int person = 0; person < P; ++person){
                        if((peopleMask >> person) & 1){
                            int personMask = (1 << person);
                            count += (dp[personMask][curMaxHat] - dp[personMask][curMaxHat - 1]) * dp[peopleMask ^ personMask][curMaxHat - 1];
                            count %= MODULO;
                        }
                    }
                    dp[peopleMask][curMaxHat] = count;
                }
            }
        }
        
        return dp[FULL_PEOPLE_MASK][MAX_HAT];
    }
};