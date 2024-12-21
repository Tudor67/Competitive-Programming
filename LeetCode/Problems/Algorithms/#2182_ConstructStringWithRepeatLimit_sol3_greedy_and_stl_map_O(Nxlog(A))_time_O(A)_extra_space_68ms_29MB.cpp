class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> charToFreq;
        for(char c: s){
            charToFreq[c] += 1;
        }

        string res;
        while(!charToFreq.empty()){
            char c = prev(charToFreq.end())->first;
            int take = min(charToFreq[c], repeatLimit);

            if(!res.empty() && res.back() == c){
                if((int)charToFreq.size() >= 2){
                    c = prev(prev(charToFreq.end()))->first;
                    take = 1;
                }else{
                    break;
                }
            }

            res.append(take, c);

            charToFreq[c] -= take;
            if(charToFreq[c] == 0){
                charToFreq.erase(c);
            }
        }

        return res;
    }
};