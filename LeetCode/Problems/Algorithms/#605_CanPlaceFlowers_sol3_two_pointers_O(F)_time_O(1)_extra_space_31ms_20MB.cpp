class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int F = flowerbed.size();
        
        // Step 1: special case (only zeros)
        if(count(flowerbed.begin(), flowerbed.end(), 0) == F){
            return ((F + 1) / 2 >= n);
        }
        
        // Step 2: count leading zeros
        int startPos = 0;
        while(startPos < F && flowerbed[startPos] == 0){
            startPos += 1;
        }
        
        // Step 3: count trailing zeros
        int endPos = F - 1;
        while(startPos < endPos && flowerbed[endPos] == 0){
            endPos -= 1;
        }
        
        // Step 4: count consecutive zeros
        int newFlowers = startPos / 2 + (F - 1 - endPos) / 2;
        int i = startPos;
        int j = startPos + 1;
        while(j <= endPos){
            if(flowerbed[j] == 1){
                newFlowers += (j - i - 2) / 2;
                i = j;
            }
            j += 1;
        }
        
        return (newFlowers >= n);
    }
};