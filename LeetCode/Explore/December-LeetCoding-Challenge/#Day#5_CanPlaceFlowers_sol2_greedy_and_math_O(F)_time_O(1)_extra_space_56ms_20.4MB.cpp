class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxFlowers = 0;
        if(count(flowerbed.begin(), flowerbed.end(), 1) == 0){
            maxFlowers = (flowerbed.size() + 1) / 2;
        }else{
            int firstPos = find(flowerbed.begin(), flowerbed.end(), 1) - flowerbed.begin();
            int lastPos = flowerbed.size() - 1 - (find(flowerbed.rbegin(), flowerbed.rend(), 1) - flowerbed.rbegin());
            maxFlowers = firstPos / 2 + (flowerbed.size() - 1 - lastPos) / 2;
            for(int i = firstPos, j = firstPos + 1; j <= lastPos; ++j){
                if(flowerbed[j] == 1){
                    int consecutiveZeros = j - i - 1;
                    maxFlowers += (consecutiveZeros - 1) / 2;
                    i = j;
                }
            }
        }
        return (maxFlowers >= n);
    }
};