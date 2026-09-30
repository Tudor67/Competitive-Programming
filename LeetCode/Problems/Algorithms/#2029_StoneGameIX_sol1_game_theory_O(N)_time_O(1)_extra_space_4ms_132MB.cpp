class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3);
        for(int val: stones){
            count[val % 3] += 1;
        }

        if(count[0] % 2 == 0){
            return (count[1] >= 1 && count[2] >= 1);
        }

        return (abs(count[1] - count[2]) >= 3);
    }
};