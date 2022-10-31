class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        const int N = plantTime.size();
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        
        sort(p.begin(), p.end(),
             [&](const int& LHS, const int& RHS){
                 return (growTime[LHS] < growTime[RHS]) ||
                        (growTime[LHS] == growTime[RHS] && plantTime[LHS] < plantTime[RHS]);
             });
        
        int leftPlantDay = -growTime[p[0]];
        for(int i = 0; i < N; ++i){
            leftPlantDay = min(leftPlantDay - plantTime[p[i]], -(plantTime[p[i]] + growTime[p[i]]));
        }
        
        return -leftPlantDay;
    }
};