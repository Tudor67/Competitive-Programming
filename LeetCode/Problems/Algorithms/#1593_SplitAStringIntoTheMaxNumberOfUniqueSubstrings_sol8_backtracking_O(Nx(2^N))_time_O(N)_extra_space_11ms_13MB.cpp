class Solution {
private:
    void back(int startIndex, unordered_set<string>& substrSet, string& s, int& res){
        if(startIndex == (int)s.length()){
            res = max(res, (int)substrSet.size());
        }else if((int)substrSet.size() + (int)s.length() - startIndex > res){
            for(int index = startIndex; index < (int)s.length(); ++index){
                string substr = s.substr(startIndex, index - startIndex + 1);
                if(!substrSet.count(substr)){
                    substrSet.insert(substr);
                    back(index + 1, substrSet, s, res);
                    substrSet.erase(substr);
                }
            }
        }
    }

public:
    int maxUniqueSplit(string s) {
        int res = 0;
        unordered_set<string> substrSet;
        back(0, substrSet, s, res);
        return res;
    }
};