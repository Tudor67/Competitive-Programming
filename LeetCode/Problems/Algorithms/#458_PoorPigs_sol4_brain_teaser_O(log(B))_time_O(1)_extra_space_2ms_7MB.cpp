class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie;
        int pigs = 0;
        int maxBuckets = 1;
        while(maxBuckets < buckets){
            maxBuckets *= (rounds + 1);
            pigs += 1;
        }
        return pigs;
    }
};