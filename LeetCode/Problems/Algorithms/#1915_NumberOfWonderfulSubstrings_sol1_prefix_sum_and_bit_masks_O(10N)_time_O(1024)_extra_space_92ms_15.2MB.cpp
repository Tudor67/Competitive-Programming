class Solution {
public:
    long long wonderfulSubstrings(string word) {
        const int N = word.length();
        const int C = 10;
        const int FULL_MASK = (1 << C) - 1;
        
        long long totalCount = 0;
        vector<long long> count(FULL_MASK + 1);
        int prefixMask = 0;
        count[0] = 1;
        for(char c: word){
            prefixMask ^= (1 << (c - 'a'));
            totalCount += count[prefixMask];
            for(int bit = 0; bit < C; ++bit){
                totalCount += count[prefixMask ^ (1 << bit)];
            }
            count[prefixMask] += 1;
        }
        
        return totalCount;
    }
};