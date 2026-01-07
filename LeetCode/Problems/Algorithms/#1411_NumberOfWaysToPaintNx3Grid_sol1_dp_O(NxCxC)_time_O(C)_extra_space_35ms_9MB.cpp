class Solution {
private:
    bool isValidConfig(int config){
        int c = config % 3;
        int b = config / 3 % 3;
        int a = config / 9 % 3;
        return (a != b && b != c);
    }

    bool areValidNeighbors(int config1, int config2){
        return (config1 % 3 != config2 % 3 &&
                config1 / 3 % 3 != config2 / 3 % 3 &&
                config1 / 9 % 3 != config2 / 9 % 3);
    }

public:
    int numOfWays(int n) {
        const int MODULO = 1'000'000'007;
        const int TOTAL_CONFIGS = 3 * 3 * 3;

        vector<int> validConfigs;
        for(int config = 0; config < TOTAL_CONFIGS; ++config){
            if(isValidConfig(config)){
                validConfigs.push_back(config);
            }
        }

        vector<int> prevDP(TOTAL_CONFIGS);
        for(int validConfig: validConfigs){
            prevDP[validConfig] = 1;
        }

        vector<int> currDP = prevDP;
        for(int row = 2; row <= n; ++row){
            fill(currDP.begin(), currDP.end(), 0);
            for(int prevValidConfig: validConfigs){
                for(int currValidConfig: validConfigs){
                    if(areValidNeighbors(prevValidConfig, currValidConfig)){
                        currDP[currValidConfig] += prevDP[prevValidConfig];
                        currDP[currValidConfig] %= MODULO;
                    }
                }
            }
            prevDP = currDP;
        }

        int res = 0;
        for(int validConfig: validConfigs){
            res += currDP[validConfig];
            res %= MODULO;
        }

        return res;
    }
};