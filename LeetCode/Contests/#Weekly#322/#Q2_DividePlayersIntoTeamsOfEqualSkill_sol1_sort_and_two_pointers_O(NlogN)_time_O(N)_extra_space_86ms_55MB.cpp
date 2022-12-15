class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        const int N = skill.size();

        vector<int> sortedSkills = skill;
        sort(sortedSkills.begin(), sortedSkills.end());

        long long totalProd = 0;
        int targetSum = sortedSkills[0] + sortedSkills[N - 1];
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            if(sortedSkills[i] + sortedSkills[j] == targetSum){
                totalProd += (sortedSkills[i] * sortedSkills[j]);
            }else{
                return -1;
            }
        }

        return totalProd;
    }
};