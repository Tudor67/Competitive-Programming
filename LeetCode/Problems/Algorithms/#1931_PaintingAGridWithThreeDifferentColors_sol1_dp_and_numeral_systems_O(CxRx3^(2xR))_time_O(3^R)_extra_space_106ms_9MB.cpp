class Solution {
private:
    bool isValidConfig(int config, const int ROWS){
        int prevColor = -1;
        for(int row = 0; row < ROWS; ++row){
            int currColor = config % 3;
            if(prevColor == currColor){
                return false;
            }
            config /= 3;
            prevColor = currColor;
        }
        return true;
    }

    bool areValidNeighbors(int config1, int config2, const int ROWS){
        for(int row = 0; row < ROWS; ++row){
            if(config1 % 3 == config2 % 3){
                return false;
            }
            config1 /= 3;
            config2 /= 3;
        }
        return true;
    }

public:
    int colorTheGrid(int ROWS, int COLS) {
        const int MODULO = 1'000'000'007;

        int distinctConfigs = 1;
        for(int row = 1; row <= ROWS; ++row){
            distinctConfigs *= 3;
        }

        vector<int> validConfigs;
        for(int config = 0; config < distinctConfigs; ++config){
            if(isValidConfig(config, ROWS)){
                validConfigs.push_back(config);
            }
        }

        const int C = validConfigs.size();
        vector<int> currDP(C, 1);
        vector<int> nextDP(C);

        for(int col = 2; col <= COLS; ++col){
            fill(nextDP.begin(), nextDP.end(), 0);

            for(int i1 = 0; i1 < C; ++i1){
                for(int i2 = 0; i2 < C; ++i2){
                    if(areValidNeighbors(validConfigs[i1], validConfigs[i2], ROWS)){
                        nextDP[i2] += currDP[i1];
                        nextDP[i2] %= MODULO;
                    }
                }
            }

            copy(nextDP.begin(), nextDP.end(), currDP.begin());
        }

        return accumulate(currDP.begin(), currDP.end(), (long long)0) % MODULO;
    }
};