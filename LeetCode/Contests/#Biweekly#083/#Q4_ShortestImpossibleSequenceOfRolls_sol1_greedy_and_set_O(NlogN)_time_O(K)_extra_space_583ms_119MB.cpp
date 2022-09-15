class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        const int N = rolls.size();
        
        int blocks = 0;
        set<int> blockSet;
        for(int i = N - 1; i >= 0; --i){
            blockSet.insert(rolls[i]);
            if((int)blockSet.size() == k){
                blockSet.clear();
                blocks += 1;
            }
        }
        
        return blocks + 1;
    }
};