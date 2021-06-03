class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        const int N = row.size();
        
        unordered_map<int, int> pos;
        for(int i = 0; i < N; ++i){
            pos[row[i]] = i;
        }
        
        int swaps = 0;
        for(int p1_pos = 0; p1_pos < N - 1; p1_pos += 2){
            int p1 = row[p1_pos];
            int p2 = (p1 % 2 == 0 ? p1 + 1 : p1 - 1);
            int p2_pos = pos[p2];
            if(p1_pos + 1 != p2_pos){
                swap(row[p1_pos + 1], row[p2_pos]);
                swaps += 1;
                pos[row[p1_pos + 1]] = p1_pos + 1;
                pos[row[p2_pos]] = p2_pos;
            }
        }
        
        return swaps;
    }
};