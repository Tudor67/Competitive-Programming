class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        int takenNums = 0;
        int sum = 0;
        for(int num = 1; num <= n; ++num){
            if(sum + num <= maxSum && !bannedSet.count(num)){
                sum += num;
                takenNums += 1;
            }
        }

        return takenNums;
    }
};