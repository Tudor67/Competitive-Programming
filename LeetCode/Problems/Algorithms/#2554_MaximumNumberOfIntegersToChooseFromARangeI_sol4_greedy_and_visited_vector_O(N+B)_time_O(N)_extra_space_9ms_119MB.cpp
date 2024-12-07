class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> isBanned(n + 1, false);
        for(int num: banned){
            if(num <= n){
                isBanned[num] = true;
            }
        }

        int takenNums = 0;
        int sum = 0;
        for(int num = 1; num <= n; ++num){
            if(sum + num <= maxSum && !isBanned[num]){
                sum += num;
                takenNums += 1;
            }
        }

        return takenNums;
    }
};