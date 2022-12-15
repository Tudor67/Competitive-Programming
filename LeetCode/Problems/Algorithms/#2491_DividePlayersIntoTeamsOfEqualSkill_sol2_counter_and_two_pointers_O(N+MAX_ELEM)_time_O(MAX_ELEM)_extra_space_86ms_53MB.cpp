class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int N = skill.size();
        const int MIN_ELEM = *min_element(skill.begin(), skill.end());
        const int MAX_ELEM = *max_element(skill.begin(), skill.end());

        vector<int> count(MAX_ELEM + 1);
        for(int elem: skill){
            count[elem] += 1;
        }

        long long totalProd = 0;
        int targetSum = MIN_ELEM + MAX_ELEM;
        int l = MIN_ELEM;
        int r = MAX_ELEM;
        while(l <= r){
            while(l <= r && count[l] == 0){
                l += 1;
            }
            while(l <= r && count[r] == 0){
                r -= 1;
            }
            if(l <= r){
                if(l + r == targetSum){
                    totalProd += (l * r);
                    count[l] -= 1;
                    count[r] -= 1;
                }else{
                    return -1;
                }
            }
        }

        return totalProd;
    }
};