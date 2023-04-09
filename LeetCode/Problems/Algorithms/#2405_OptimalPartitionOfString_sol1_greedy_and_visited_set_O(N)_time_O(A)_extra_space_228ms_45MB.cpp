class Solution {
public:
    int partitionString(string s) {
        const int N = s.length();

        int res = 1;
        unordered_set<char> vis;
        for(char c: s){
            if(vis.count(c)){
                res += 1;
                vis.clear();
            }
            vis.insert(c);
        }

        return res;
    }
};