class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& reqSkills, vector<vector<string>>& people) {
        const int P = people.size();
        const int R = reqSkills.size();
        const int FULL_MASK = (1 << R) - 1;
        const int INF = 1e9;

        unordered_map<string, int> skillToIndex;
        for(int i = 0; i < R; ++i){
            skillToIndex[reqSkills[i]] = i;
        }

        // dp[bitmask]: size of the smallest team that has all the skills encoded in the bitmask
        //              (if the ith bit of the bitmask is 1, then the team has the ith skill)
        // prevMask[bitmask]: previous mask before reaching the smallest team with skills encoded in the bitmask
        // lastPerson[bitmask]: last person of the smallest team with skills encoded in the bitmask
        vector<int> dp(FULL_MASK + 1, INF);
        vector<int> prevMask(FULL_MASK + 1);
        vector<int> lastPerson(FULL_MASK + 1);
        dp[0] = 0;

        for(int i = 0; i < P; ++i){
            int personSkillsMask = 0;
            for(const string& SKILL: people[i]){
                personSkillsMask |= (1 << skillToIndex[SKILL]);
            }

            for(int mask = 0; mask <= FULL_MASK; ++mask){
                int nextMask = mask | personSkillsMask;
                if(dp[mask] + 1 < dp[nextMask]){
                    dp[nextMask] = dp[mask] + 1;
                    prevMask[nextMask] = mask;
                    lastPerson[nextMask] = i;
                }
            }
        }

        vector<int> res;
        for(int mask = FULL_MASK; mask != prevMask[mask]; mask = prevMask[mask]){
            res.push_back(lastPerson[mask]);
        }

        return res;
    }
};