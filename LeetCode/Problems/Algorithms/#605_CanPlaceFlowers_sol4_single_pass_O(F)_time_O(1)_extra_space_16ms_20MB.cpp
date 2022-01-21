class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        const int F = flowerbed.size();
        int newFlowers = 0;
        int i = 0;
        while(i < F){
            if(flowerbed[i] == 0){
                if((i - 1 < 0  || flowerbed[i - 1] == 0) &&
                   (i + 1 == F || flowerbed[i + 1] == 0)){
                       newFlowers += 1;
                       i += 2;
                   }else{
                       i += 1;
                   }
            }else{
                i += 2;
            }
        }
        return (newFlowers >= n);
    }
};