class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> freq;
        for(char c: s){
            freq[c] += 1;
        }

        set<pair<char, int>> cfSet;
        for(auto [c, f]: freq){
            cfSet.insert({c, f});
        }

        string res;
        while(!cfSet.empty()){
            char c = cfSet.rbegin()->first;
            int take = min(freq[c], repeatLimit);

            if(!res.empty() && res.back() == c){
                if((int)cfSet.size() >= 2){
                    c = next(cfSet.rbegin())->first;
                    take = 1;
                }else{
                    break;
                }
            }

            cfSet.erase({c, freq[c]});
            freq[c] -= take;
            if(freq[c] >= 1){
                cfSet.insert({c, freq[c]});
            }

            res.append(take, c);
        }

        return res;
    }
};