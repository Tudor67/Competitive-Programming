class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMask;
        for(const vector<int>& RC: reservedSeats){
            int row = RC[0] - 1;
            int col = RC[1] - 1;
            reservedMask[row] |= (1 << col);
        }
        
        int maxGroups = 2 * n;
        const int MASK29 = stoi("0111111110", NULL, 2);
        const int MASK25 = stoi("0111100000", NULL, 2);
        const int MASK47 = stoi("0001111000", NULL, 2);
        const int MASK69 = stoi("0000011110", NULL, 2);
        for(const pair<int, int>& P: reservedMask){
            int mask = P.second;
            if((mask & MASK29) == 0){
                // ok
            }else if((mask & MASK25) == 0 || (mask & MASK47) == 0 || (mask & MASK69) == 0){
                maxGroups -= 1;
            }else{
                maxGroups -= 2;
            }
        }
        
        return maxGroups;
    }
};