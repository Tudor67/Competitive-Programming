class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int F = fruits.size();

        int res = 0;
        int l = 0;
        unordered_map<int, int> count;

        for(int r = 0; r < F; ++r){
            count[fruits[r]] += 1;
            while((int)count.size() >= 3){
                count[fruits[l]] -= 1;
                if(count[fruits[l]] == 0){
                    count.erase(fruits[l]);
                }
                l += 1;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};