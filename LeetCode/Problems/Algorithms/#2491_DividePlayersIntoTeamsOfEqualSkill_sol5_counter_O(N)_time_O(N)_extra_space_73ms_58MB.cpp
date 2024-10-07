class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        const int N = skills.size();

        unordered_map<int, int> freq;
        int minSkill = skills[0];
        int maxSkill = skills[0];
        for(int skill: skills){
            freq[skill] += 1;
            minSkill = min(minSkill, skill);
            maxSkill = max(maxSkill, skill);
        }

        long long chemistry = 0;
        int targetSum = minSkill + maxSkill;
        for(int skill: skills){
            if(freq[skill] >= 1){
                freq[skill] -= 1;
                int complSkill = targetSum - skill;
                if(freq.count(complSkill) && freq[complSkill] >= 1){
                    freq[complSkill] -= 1;
                    chemistry += (skill * complSkill);
                }else{
                    return -1;
                }
            }
        }

        return chemistry;
    }
};