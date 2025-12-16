class Solution {
private:
    int countOdds(int n){
        return (n + 1) / 2;
    }

public:
    int countOdds(int low, int high) {
        return countOdds(high) - countOdds(low - 1);
    }
};