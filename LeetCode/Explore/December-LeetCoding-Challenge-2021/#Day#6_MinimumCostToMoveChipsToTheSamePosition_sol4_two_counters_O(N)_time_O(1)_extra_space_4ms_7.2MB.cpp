class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        const int N = position.size();
        
        int evenPositions = 0;
        int oddPositions = 0;
        for(int i = 0; i < N; ++i){
            if(position[i] % 2 == 0){
                ++evenPositions;
            }else{
                ++oddPositions;
            }
        }
        
        return min(evenPositions, oddPositions);
    }
};