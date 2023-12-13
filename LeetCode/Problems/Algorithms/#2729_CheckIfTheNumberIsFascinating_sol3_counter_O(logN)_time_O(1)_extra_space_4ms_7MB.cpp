class Solution {
private:
    void updateFreq(int n, vector<int>& freq){
        if(n == 0){
            freq[0] += 1;
        }else{
            while(n > 0){
                freq[n % 10] += 1;
                n /= 10;
            }
        }
    }

public:
    bool isFascinating(int n) {
        vector<int> freq(10);
        updateFreq(n, freq);
        updateFreq(2 * n, freq);
        updateFreq(3 * n, freq);

        if(freq[0] != 0){
            return false;
        }

        for(int digit = 1; digit <= 9; ++digit){
            if(freq[digit] != 1){
                return false;
            }
        }
        
        return true;
    }
};