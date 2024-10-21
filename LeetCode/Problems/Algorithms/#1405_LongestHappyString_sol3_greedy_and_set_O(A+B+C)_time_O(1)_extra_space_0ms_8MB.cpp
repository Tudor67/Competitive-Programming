class Solution {
private:
    void insert(set<pair<int, char>>& s, int cFreq, char c){
        if(cFreq >= 1){
            s.insert({cFreq, c});
        }
    }

public:
    string longestDiverseString(int a, int b, int c) {
        set<pair<int, char>> s;
        insert(s, a, 'a');
        insert(s, b, 'b');
        insert(s, c, 'c');

        string res;
        while(!s.empty()){
            int cFreq = prev(s.end())->first;
            char c = prev(s.end())->second;

            int resLen = res.length();
            if(resLen >= 2 && res[resLen - 2] == c && res[resLen - 1] == c){
                if((int)s.size() >= 2){
                    cFreq = prev(prev(s.end()))->first;
                    c = prev(prev(s.end()))->second;
                }else{
                    break;
                }
            }

            res += c;

            s.erase({cFreq, c});
            if(cFreq - 1 >= 1){
                s.insert({cFreq - 1, c});
            }
        }

        return res;
    }
};