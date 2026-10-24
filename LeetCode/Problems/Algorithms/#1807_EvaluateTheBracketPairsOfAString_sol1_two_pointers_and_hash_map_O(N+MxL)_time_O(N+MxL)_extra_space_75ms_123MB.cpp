class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        const int N = s.length();

        unordered_map<string, string> valueOf;
        for(vector<string>& kv: knowledge){
            string& key = kv[0];
            string& value = kv[1];
            valueOf[key] = value;
        }

        string res;
        
        int i = 0;
        while(i < N){
            if(s[i] == '('){
                size_t j = s.find(')', i);
                string currKey = s.substr(i + 1, j - i - 1);
                if(valueOf.contains(currKey)){
                    res += valueOf[currKey];
                }else{
                    res += '?';
                }
                i = j + 1;
            }else{
                res += s[i];
                i += 1;
            }
        }

        return res;
    }
};