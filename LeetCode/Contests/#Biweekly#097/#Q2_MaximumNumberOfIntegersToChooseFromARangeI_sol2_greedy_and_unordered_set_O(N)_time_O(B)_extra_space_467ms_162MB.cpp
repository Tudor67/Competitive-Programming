class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum = 0;
        int count = 0;

        unordered_set<int> bannedSet(banned.begin(), banned.end());

        for(int num = 1; num <= n; ++num){
            if(!bannedSet.count(num)){
                if(sum + num <= maxSum){
                    sum += num;
                    count += 1;
                }else{
                    return count;
                }
            }
        }

        return count;
    }
};