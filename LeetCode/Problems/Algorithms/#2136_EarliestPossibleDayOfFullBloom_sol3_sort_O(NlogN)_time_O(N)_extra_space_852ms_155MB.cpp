class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        const int N = plantTime.size();
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        
        sort(p.begin(), p.end(),
             [&](const int& LHS, const int& RHS){
                 return (growTime[LHS] > growTime[RHS]);
             });
        
        int plantDay = 0;
        int lastBloomDay = 0;
        for(int i = 0; i < N; ++i){
            lastBloomDay = max(lastBloomDay, plantDay + plantTime[p[i]] + growTime[p[i]]);
            plantDay += plantTime[p[i]];
        }
        
        return lastBloomDay;
    }
};