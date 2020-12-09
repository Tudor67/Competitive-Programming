class Solution {
private:
    vector<int> maskToVector(const long long& MASK){
        vector<int> positions;
        for(int i = 0; i < 60; ++i){
            if((MASK >> i) & 1){
                positions.push_back(i);
            }
        }
        return positions;
    }
    
public:
    vector<int> smallestSufficientTeam(vector<string>& reqSkills, vector<vector<string>>& people) {
        unordered_map<string, int> idxOf;
        for(int i = 0; i < reqSkills.size(); ++i){
            idxOf[reqSkills[i]] = i;
        }
        
        const int P = people.size();
        vector<int> peopleSkillsMask(P, 0);
        for(int i = 0; i < P; ++i){
            for(const string& SKILL: people[i]){
                peopleSkillsMask[i] |= (1 << idxOf[SKILL]);
            }
        }
        
        const int REQ_SKILLS_FULL_MASK = (1 << reqSkills.size()) - 1;
        unordered_set<int> vis;
        vis.insert(0);
        queue<pair<int, long long>> q;
        q.push({0, 0});
        
        while(!q.empty()){
            int skillMask = q.front().first;
            long long teamMask = q.front().second;
            q.pop();
            
            for(int i = 0; i < P; ++i){
                int nextSkillMask = skillMask | peopleSkillsMask[i];
                long long nextTeamMask = teamMask | (1LL << i);
                if(!vis.count(nextSkillMask)){
                    q.push({nextSkillMask, nextTeamMask});
                    vis.insert(nextSkillMask);
                }
                if(nextSkillMask == REQ_SKILLS_FULL_MASK){
                    return maskToVector(nextTeamMask);
                }
            }
        }
        
        return {};
    }
};