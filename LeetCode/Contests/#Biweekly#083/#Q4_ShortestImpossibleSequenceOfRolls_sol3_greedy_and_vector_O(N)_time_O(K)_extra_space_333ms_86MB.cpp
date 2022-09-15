class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        const int N = rolls.size();
        
        int blocks = 0;
        int blockUniqueValues = 0;
        vector<bool> vis(k + 1, false);
        for(int i = N - 1; i >= 0; --i){
            blockUniqueValues += (int)(!vis[rolls[i]]);
            vis[rolls[i]] = true;
            if(blockUniqueValues == k){
                blocks += 1;
                fill(vis.begin(), vis.end(), false);
                blockUniqueValues = 0;
            }
        }
        
        return blocks + 1;
    }
};