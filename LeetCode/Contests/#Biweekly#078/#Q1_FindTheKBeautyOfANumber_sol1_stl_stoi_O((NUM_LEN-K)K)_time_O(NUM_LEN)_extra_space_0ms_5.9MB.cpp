class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numStr = to_string(num);
        const int NUM_LEN = numStr.length();
        
        int count = 0;
        for(int i = 0; i + k - 1 < NUM_LEN; ++i){
            int x = stoi(numStr.substr(i, k));
            if(x != 0 && num % x == 0){
                count += 1;
            }
        }
        
        return count;
    }
};