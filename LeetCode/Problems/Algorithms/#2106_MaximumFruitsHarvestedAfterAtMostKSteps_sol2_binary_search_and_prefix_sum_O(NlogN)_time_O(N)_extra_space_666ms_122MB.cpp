class Solution {
private:
    int binarySearch(vector<vector<int>>& fruits, vector<int>& fruitsPrefSum, int startPos, int l, int r, int k, int i){
        while(l != r){
            int mid = (l + r) / 2;
            if(startPos - fruits[mid][0] > k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        int fruitsSum = fruitsPrefSum[i];
        if(l - 1 >= 0){
            fruitsSum -= fruitsPrefSum[l - 1];
        }
        return fruitsSum;
    }
    
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int N = fruits.size();
        
        vector<int> fruitsPrefSum(N);
        fruitsPrefSum[0] = fruits[0][1];
        for(int i = 1; i < N; ++i){
            fruitsPrefSum[i] = fruitsPrefSum[i - 1] + fruits[i][1];
        }
        
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
        
        int maxFruits = max(fruitsLeft, fruitsRight);
        int startIdx = N;
        for(int i = 0; i < N; ++i){
            int currentPos = fruits[i][0];
            if(currentPos - startPos > k){
                break;
            }
            if(startPos <= currentPos){
                startIdx = min(startIdx, i);
                int rightDist = currentPos - startPos;
                int fruitsRightLeft = binarySearch(fruits, fruitsPrefSum, startPos, 0, startIdx, k - 2 * rightDist, i);
                int fruitsLeftRight = binarySearch(fruits, fruitsPrefSum, startPos, 0, startIdx, (k - rightDist) / 2, i);
                maxFruits = max(maxFruits, max(fruitsRightLeft, fruitsLeftRight));
            }
        }
        
        return maxFruits;
    }
};