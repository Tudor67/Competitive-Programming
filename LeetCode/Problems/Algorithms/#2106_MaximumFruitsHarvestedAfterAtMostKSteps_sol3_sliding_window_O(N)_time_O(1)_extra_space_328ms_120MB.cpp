class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int N = fruits.size();
        
        int fruitsLeft = 0;
        int fruitsRight = 0;
        for(int i = 0; i < N; ++i){
            int currentPos = fruits[i][0];
            int currentFruits = fruits[i][1];
            if(currentPos <= startPos && startPos - currentPos <= k){
                fruitsLeft += currentFruits;
            }
            if(startPos <= currentPos && currentPos - startPos <= k){
                fruitsRight += currentFruits;
            }
        }
        
        int maxFruitsSum = max(fruitsLeft, fruitsRight);
        
        int fruitsSum = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            int currentPos = fruits[j][0];
            fruitsSum += fruits[j][1];
            if(startPos <= currentPos){
                while(currentPos - fruits[i][0] + min(currentPos - startPos, startPos - fruits[i][0]) > k){
                    fruitsSum -= fruits[i][1];
                    i += 1;
                }
                if(fruits[i][0] <= startPos){
                    maxFruitsSum = max(maxFruitsSum, fruitsSum);
                }else{
                    break;
                }
            }
        }
        
        return maxFruitsSum;
    }
};