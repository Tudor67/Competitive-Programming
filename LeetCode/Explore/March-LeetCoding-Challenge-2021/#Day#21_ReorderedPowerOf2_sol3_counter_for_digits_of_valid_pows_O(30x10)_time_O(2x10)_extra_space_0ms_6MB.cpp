class Solution {
private:
    void countDigits(int num, vector<int>& count){
        fill(count.begin(), count.end(), 0);
        while(num != 0){
            count[num % 10] += 1;
            num /= 10;
        }
    }
    
public:
    bool reorderedPowerOf2(int N) {
        vector<int> currentCounts(10);
        vector<int> targetCounts(10);
        countDigits(N, currentCounts);
        for(int p = 1; p <= INT_MAX / 2; p *= 2){
            countDigits(p, targetCounts);
            if(currentCounts == targetCounts){
                return true;
            }
        }
        return false;
    }
};