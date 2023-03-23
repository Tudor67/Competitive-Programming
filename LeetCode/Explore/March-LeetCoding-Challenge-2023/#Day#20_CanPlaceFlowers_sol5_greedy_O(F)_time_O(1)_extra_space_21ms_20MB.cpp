class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int F = flowerbed.size();

        int newFlowers = 0;
        int prevFlowerIndex = -2;
        for(int i = 0; i < F; ++i){
            if(flowerbed[i] == 0){
                bool emptyPrevIndex = (prevFlowerIndex != i - 1);
                bool emptyNextIndex = (i + 1 >= F || flowerbed[i + 1] == 0);
                if(emptyPrevIndex && emptyNextIndex){
                    prevFlowerIndex = i;
                    newFlowers += 1;
                }
            }else{
                prevFlowerIndex = i;
            }
        }

        return (newFlowers >= n);
    }
};