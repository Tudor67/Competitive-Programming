class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        
        int base = rounds + 1;
        int p = 1;
        int n = 0;
        while(p < buckets){
            p *= base;
            n += 1;
        }
        
        return n;
    }
};