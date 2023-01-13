class Solution {
public:
    int secondHighest(string s) {
        const int N = s.length();

        vector<bool> vis(10, false);
        for(char c: s){
            if(isdigit(c)){
                vis[c - '0'] = true;
            }
        }

        int visCount = 0;
        for(int c = '9'; c >= '0'; --c){
            if(vis[c - '0']){
                visCount += 1;
            }
            if(visCount >= 2){
                return (c - '0');
            }
        }

        return -1;
    }
};