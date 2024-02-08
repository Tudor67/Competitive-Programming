class Solution {
public:
    string finalString(string s) {
        const int N = s.length();
        
        deque<char> dq;
        int dir = 1;
        
        for(char c: s){
            if(c == 'i'){
                dir ^= 1;
            }else if(dir == 0){
                dq.push_front(c);
            }else{
                dq.push_back(c);
            }
        }

        if(dir == 1){
            return string(dq.begin(), dq.end());
        }
        return string(dq.rbegin(), dq.rend());
    }
};