class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int chipsAtEvenPos = 0;
        int chipsAtOddPos = 0;
        for(int pos: position){
            if(pos % 2 == 0){
                chipsAtEvenPos += 1;
            }else{
                chipsAtOddPos += 1;
            }
        }
        int minCost = min(chipsAtEvenPos, chipsAtOddPos);
        return minCost;
    }
};