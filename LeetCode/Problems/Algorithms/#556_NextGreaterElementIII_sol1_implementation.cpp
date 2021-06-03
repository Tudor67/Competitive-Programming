class Solution {
public:
    int nextGreaterElement(int n) {
        int answer = -1;
        
        const string MAX_S = to_string(INT_MAX);
        string s = to_string(n);
        for(int i = (int)s.length() - 1; i >= 1; --i){
            if(s[i - 1] < s[i]){
                for(int j = (int)s.length() - 1; j >= i; --j){
                    if(s[i - 1] < s[j]){
                        swap(s[i - 1], s[j]);
                        break;
                    }
                }
                reverse(s.begin() + i, s.end());
                if(s.length() < MAX_S.length() || (s.length() == MAX_S.length() && s <= MAX_S)){
                    answer = stoi(s);
                }
                break;
            }
        }
        
        return answer;
    }
};