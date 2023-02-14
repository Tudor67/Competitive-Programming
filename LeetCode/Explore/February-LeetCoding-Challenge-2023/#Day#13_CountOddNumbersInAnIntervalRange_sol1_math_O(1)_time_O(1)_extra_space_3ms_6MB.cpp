class Solution {
public:
    int countOdds(int low, int high) {
        int rangeSize = high - low + 1;
        int oddNumsCount = rangeSize / 2;
        if(rangeSize % 2 == 1 && high % 2 == 1){
            oddNumsCount += 1;
        }
        return oddNumsCount;
    }
};