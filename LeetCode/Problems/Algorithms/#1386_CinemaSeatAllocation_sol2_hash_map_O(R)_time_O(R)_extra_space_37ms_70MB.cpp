class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> reservedAt;
        for(vector<int>& reservation: reservedSeats){
            int row = reservation[0];
            int col = reservation[1];
            reservedAt[row].push_back(col);
        }

        int maxGroups = 2 * n;
        vector<bool> ok(11);
        for(auto& [_, cols]: reservedAt){
            fill(ok.begin(), ok.end(), true);
            for(int col: cols){
                ok[col] = false;
            }

            int validGroups = max((int)(ok[2] && ok[3] && ok[4] && ok[5])
                                   +
                                  (int)(ok[6] && ok[7] && ok[8] && ok[9]),
                                  (int)(ok[4] && ok[5] && ok[6] && ok[7]));

            int invalidGroups = 2 - validGroups;
            
            maxGroups -= invalidGroups;
        }

        return maxGroups;
    }
};