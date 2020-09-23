class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXOR = 0;
        
        // build the answer (i.e., maxXOR) step-by-step moving from left (msb) to right (lsb)
        int mask = 0;
        for(int bit = 30; bit >= 0; --bit){
            mask |= (1 << bit);
            
            // save prefixes with the first (30 - bit + 1) most significant bits
            set<int> prefixes;
            for(int num: nums){
                prefixes.insert(num & mask);
            }
            
            // try to improve/maximize current maxXOR with one more bit (if possible)
            for(int prefix: prefixes){
                if(prefixes.find(prefix ^ (maxXOR | (1 << bit))) != prefixes.end()){
                    maxXOR |= (1 << bit);
                    break;
                }
            }
        }
        
        return maxXOR;
    }
};