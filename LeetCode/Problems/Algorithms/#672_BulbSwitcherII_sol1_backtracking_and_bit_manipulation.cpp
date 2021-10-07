class Solution {
private:
    void applyXOR(int& mask, const int& START_BIT, const int& END_BIT, const int& STEP_SIZE){
        for(int bit = START_BIT; bit < END_BIT; bit += STEP_SIZE){
            mask ^= (1 << bit);
        }
    }
    
    void back(int config, int n, int presses, set<int>& configSet){
        if(presses == 0){
            configSet.insert(config);
        }else{
            for(int operation = 1; operation <= 4; ++operation){
                int nextConfig = config;
                if(operation == 1){
                    applyXOR(nextConfig, 0, n, 1);
                }else if(operation == 2){
                    applyXOR(nextConfig, 1, n, 2);
                }else if(operation == 3){
                    applyXOR(nextConfig, 0, n, 2);
                }else if(operation == 4){
                    applyXOR(nextConfig, 0, n, 3);
                }
                back(nextConfig, n, presses - 1, configSet);
            }
        }
    }
    
public:
    int flipLights(int n, int presses) {
        n = min(4, n);
        presses = min(3, presses);
        
        set<int> configSet;
        back((1 << n) - 1, n, presses, configSet);
        
        return configSet.size();
    }
};