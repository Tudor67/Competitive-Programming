class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res = 0;
        for(int i = 0; i <= total / cost1; ++i){
            res += (total - i * cost1) / cost2 + 1;
        }
        return res;
    }
};