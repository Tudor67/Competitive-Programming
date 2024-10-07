class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        const int N = skills.size();

        vector<int> sortedSkills = skills;
        sort(sortedSkills.begin(), sortedSkills.end());

        long long chemistry = 0;
        int targetSum = sortedSkills[0] + sortedSkills[N - 1];
        for(int i = 0, j = N - 1; i < j; ++i, --j){
            if(sortedSkills[i] + sortedSkills[j] == targetSum){
                chemistry += (sortedSkills[i] * sortedSkills[j]);
            }else{
                return -1;
            }
        }

        return chemistry;
    }
};