class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int steps = minutesToTest / minutesToDie;
        return ceil(log(buckets) / log(steps + 1));
    }
};