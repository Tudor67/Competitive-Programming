class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        const int F = flowers.size();
        const int P = persons.size();
        
        vector<int> startTimes(F);
        vector<int> endTimes(F);
        for(int i = 0; i < F; ++i){
            startTimes[i] = flowers[i][0];
            endTimes[i] = flowers[i][1];
        }
        
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        vector<int> answer(P);
        for(int j = 0; j < P; ++j){
            int startPoints = upper_bound(startTimes.begin(), startTimes.end(), persons[j]) - startTimes.begin();
            int endPoints = lower_bound(endTimes.begin(), endTimes.end(), persons[j]) - endTimes.begin();
            answer[j] = startPoints - endPoints;
        }
        
        return answer;
    }
};