class Solution {
private:
    void rec(int i, string substr, unordered_set<string>& substrSet, string& s, int& res){
        if(i == (int)s.length()){
            if(substr.empty()){
                res = max(res, (int)substrSet.size());
            }
        }else{
            substr += s[i];
            rec(i + 1, substr, substrSet, s, res);
            if(!substrSet.count(substr)){
                substrSet.insert(substr);
                rec(i + 1, "", substrSet, s, res);
                substrSet.erase(substr);
            }
        }
    }

public:
    int maxUniqueSplit(string s) {
        int res = 0;
        unordered_set<string> substrSet;
        rec(0, "", substrSet, s, res);
        return res;
    }
};