class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_BIT = 30;
        
        // build the answer (i.e., maxXOR) step-by-step by moving from left (msb) to right (lsb)
        int maxXOR = 0;
        int prefixFullMask = 0;
        unordered_set<int> prefixes;
        for(int bit = MAX_BIT; bit >= 0; --bit){
            prefixFullMask |= (1 << bit);
            
            // store all num prefixes with the first MAX_BIT - bit + 1 most significant bits
            prefixes.clear();
            for(int num: nums){
                prefixes.insert(num & prefixFullMask);
            }
            
            // try to maximize maxXOR with one more 1-bit (if possible)
            //       find a pair (prefix, prefixComplement)
            //       such that (prefix ^ prefixComplement) == (maxXOR | (1 << bit))
            for(int prefix: prefixes){
                int prefixComplement = (maxXOR | (1 << bit)) ^ prefix;
                if(prefixes.count(prefixComplement)){
                    maxXOR |= (1 << bit);
                    break;
                }
            }
        }
        
        return maxXOR;
    }
};