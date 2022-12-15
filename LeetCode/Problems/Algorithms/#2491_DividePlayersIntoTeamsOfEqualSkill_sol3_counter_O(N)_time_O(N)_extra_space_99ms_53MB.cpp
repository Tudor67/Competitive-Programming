class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int N = skill.size();
        const int TOTAL_SUM = accumulate(skill.begin(), skill.end(), 0);
        const int TARGET_SUM = 2 * TOTAL_SUM / N;

        unordered_map<int, int> count;
        for(int elem: skill){
            count[elem] += 1;
        }

        long long totalProd = 0;
        for(const pair<int, int>& P: count){
            int a = P.first;
            int b = TARGET_SUM - a;
            if(count.count(b) && count[a] == count[b]){
                totalProd += (a * (long long)count[a] * b);
            }else{
                return -1;
            }
        }

        return totalProd / 2;
    }
};