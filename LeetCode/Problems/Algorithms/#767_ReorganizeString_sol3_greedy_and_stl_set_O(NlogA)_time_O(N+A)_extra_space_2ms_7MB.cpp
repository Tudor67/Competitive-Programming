class Solution {
public:
    string reorganizeString(string s) {
        const int N = s.length();

        unordered_map<char, int> count;
        for(char c: s){
            count[c] += 1;
        }

        set<pair<int, char>> countCharSet;
        for(const pair<char, int>& P: count){
            char c = P.first;
            countCharSet.insert({count[c], c});
        }

        string res;
        while((int)countCharSet.size() >= 2){
            char a = prev(countCharSet.end())->second;
            countCharSet.erase(prev(countCharSet.end()));

            char b = prev(countCharSet.end())->second;
            countCharSet.erase(prev(countCharSet.end()));

            res += a;
            res += b;

            count[a] -= 1;
            count[b] -= 1;

            if(count[a] >= 1){
                countCharSet.insert({count[a], a});
            }
            if(count[b] >= 1){
                countCharSet.insert({count[b], b});
            }
        }

        if((int)countCharSet.size() == 1){
            char a = prev(countCharSet.end())->second;
            if(count[a] == 1){
                count[a] -= 1;
                res += a;
            }else{
                res.clear();
            }
        }

        return res;
    }
};