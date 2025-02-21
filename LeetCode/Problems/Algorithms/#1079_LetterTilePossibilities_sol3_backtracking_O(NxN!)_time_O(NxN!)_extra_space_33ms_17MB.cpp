class Solution {
private:
    void back(int visMask, string& st, string& tiles, unordered_set<string>& seqsSet){
        seqsSet.insert(st);
        for(int i = 0; i < (int)tiles.size(); ++i){
            if(((visMask >> i) & 1) == 0){
                st.push_back(tiles[i]);
                back(visMask | (1 << i), st, tiles, seqsSet);
                st.pop_back();
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        string st;
        unordered_set<string> seqsSet;
        back(0, st, tiles, seqsSet);
        return (int)seqsSet.size() - 1;
    }
};