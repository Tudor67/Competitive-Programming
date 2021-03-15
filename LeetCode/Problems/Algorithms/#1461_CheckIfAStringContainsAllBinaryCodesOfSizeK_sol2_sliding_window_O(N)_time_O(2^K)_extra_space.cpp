class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int MAX_NUM = (1 << k);
        vector<bool> vis(MAX_NUM, false);
        for(int i = 0, num = 0; i < (int)s.length(); ++i){
            num = (2 * num + (s[i] - '0')) % MAX_NUM;
            if(i >= k - 1){
                vis[num] = true;
            }
        }
        return (count(vis.begin(), vis.end(), true) == MAX_NUM);
    }
};