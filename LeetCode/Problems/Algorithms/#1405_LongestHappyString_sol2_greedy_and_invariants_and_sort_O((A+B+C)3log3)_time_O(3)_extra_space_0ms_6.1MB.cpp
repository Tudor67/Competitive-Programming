class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> freqChar = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        string res;
        while(true){
            sort(freqChar.rbegin(), freqChar.rend());
            
            int i = 0;
            int n = res.size();
            if(n >= 2 && res[n - 2] == freqChar[0].second && res[n - 1] == freqChar[0].second){
                i = 1;
            }
            
            if(freqChar[i].first >= 1){
                freqChar[i].first -= 1;
                res += freqChar[i].second;
            }else{
                break;
            }
        }
        
        return res;
    }
};