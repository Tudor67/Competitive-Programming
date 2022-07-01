class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        const int N = aliceValues.size();
        
        vector<pair<int, int>> contribIdx(N);
        for(int i = 0; i < N; ++i){
            contribIdx[i] = {aliceValues[i] + bobValues[i], i};
        }
        
        sort(contribIdx.rbegin(), contribIdx.rend());
        
        int alicePoints = 0;
        int bobPoints = 0;
        for(int i = 0; i < N; ++i){
            if(i % 2 == 0){
                alicePoints += aliceValues[contribIdx[i].second];
            }else{
                bobPoints += bobValues[contribIdx[i].second];
            }
        }
        
        if(alicePoints > bobPoints){
            return 1;
        }else if(alicePoints < bobPoints){
            return -1;
        }
        return 0;
    }
};