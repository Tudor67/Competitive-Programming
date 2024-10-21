class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;

        vector<pair<int, char>> fc = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while(true){
            sort(fc.begin(), fc.end());

            int i = (int)fc.size() - 1;
            int resLen = res.length();
            if(resLen >= 2 && res[resLen - 2] == fc[i].second && res[resLen - 1] == fc[i].second){
                i -= 1;
            }

            if(fc[i].first >= 1){
                res += fc[i].second;
                fc[i].first -= 1;
            }else{
                break;
            }
        }

        return res;
    }
};