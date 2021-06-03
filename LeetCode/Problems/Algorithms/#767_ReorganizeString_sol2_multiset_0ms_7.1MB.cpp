class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(128, 0);
        for(char c: S){
            cnt[c] += 1;
        }
        
        multiset<pair<int, char>> cntChar;
        for(char c = 'a'; c <= 'z'; ++c){
            if(cnt[c] > 0){
                cntChar.insert({cnt[c], c});
            }
        }
        
        string answer;
        while(!cntChar.empty()){
            multiset<pair<int, char>>::iterator it = prev(cntChar.end());
            char c = it->second;
            if(!answer.empty() && answer.back() == c){
                if(cntChar.size() >= 2){
                    it = prev(cntChar.end(), 2);
                    c = it->second;
                }else{
                    // not possible
                    answer = "";
                    break;
                }
            }
            answer.push_back(c);
            cntChar.erase(it);
            cnt[c] -= 1;
            if(cnt[c] > 0){
                cntChar.insert({cnt[c], c});
            }
        }
        
        return answer;
    }
};