class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxFlowers = 0;
        int i = 0;
        while(i < flowerbed.size() && n > 0){
            if(flowerbed[i] == 0){
                int isPrevEmpty = (i - 1 == -1 ? true : flowerbed[i - 1] == 0);
                int isNextEmpty = (i + 1 == flowerbed.size() ? true : flowerbed[i + 1] == 0);
                if(isPrevEmpty && isNextEmpty){
                    maxFlowers += 1;
                    i += 2;
                }else{
                    i += 1;
                }
            }else{
                i += 1;
            }
        }
        return (maxFlowers >= n);
    }
};