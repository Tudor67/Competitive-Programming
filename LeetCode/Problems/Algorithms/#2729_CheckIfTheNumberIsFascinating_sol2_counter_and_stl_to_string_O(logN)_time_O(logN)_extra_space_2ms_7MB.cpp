class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2 * n) + to_string(3 * n);
        
        vector<int> freq(10);
        for(char c: s){
            freq[c - '0'] += 1;
        }

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