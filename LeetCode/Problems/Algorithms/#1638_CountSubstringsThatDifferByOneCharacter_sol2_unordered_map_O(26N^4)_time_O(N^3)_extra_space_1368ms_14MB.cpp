class Solution {
public:
    int countSubstrings(string s, string t) {
        unordered_map<string, int> tCnt;
        for(int pos = 0; pos < t.length(); ++pos){
            for(int len = 1; pos + len - 1 < t.length(); ++len){
                tCnt[t.substr(pos, len)] += 1;
            }
        }
        
        int answer = 0;
        for(int pos = 0; pos < s.length(); ++pos){
            for(int len = 1; pos + len - 1 < s.length(); ++len){
                string sSubstr = s.substr(pos, len);
                for(int i = 0; i < sSubstr.length(); ++i){
                    char originalChar = sSubstr[i];
                    for(int newChar = 'a'; newChar <= 'z'; ++newChar){
                        if(newChar != originalChar){
                            sSubstr[i] = newChar;
                            if(tCnt.count(sSubstr)){
                                answer += tCnt[sSubstr];
                            }
                        }
                    }
                    sSubstr[i] = originalChar;
                }
            }
        }
        
        return answer;
    }
};