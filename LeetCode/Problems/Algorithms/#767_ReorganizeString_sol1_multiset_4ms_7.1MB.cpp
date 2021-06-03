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
            char c1 = prev(cntChar.end())->second;
            if(answer.empty() || answer.back() != c1){
                answer.push_back(c1);
                cntChar.erase(prev(cntChar.end()));
                cnt[c1] -= 1;
                if(cnt[c1] > 0){
                    cntChar.insert({cnt[c1], c1});
                }
            }else{
                if(cntChar.size() >= 2){
                    c1 = prev(cntChar.end(), 2)->second;
                    answer.push_back(c1);
                    cntChar.erase(prev(cntChar.end(), 2));
                    cnt[c1] -= 1;
                    if(cnt[c1] > 0){
                        cntChar.insert({cnt[c1], c1});
                    }
                }else{
                    // not possible
                    answer = "";
                    break;
                }
            }
        }
        
        return answer;
    }
};