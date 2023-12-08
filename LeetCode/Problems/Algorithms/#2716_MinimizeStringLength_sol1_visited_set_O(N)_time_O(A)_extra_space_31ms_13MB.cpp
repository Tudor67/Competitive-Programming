class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> vis;
        for(char c: s){
            vis.insert(c);
        }
        return vis.size();
    }
};