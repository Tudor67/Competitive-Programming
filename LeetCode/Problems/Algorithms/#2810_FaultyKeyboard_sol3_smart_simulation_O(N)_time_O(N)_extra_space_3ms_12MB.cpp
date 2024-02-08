class Solution {
public:
    string finalString(string s) {
        string a;
        string b;

        for(char c: s){
            if(c == 'i'){
                swap(a, b);
            }else{
                a += c;
            }
        }
        
        return string(b.rbegin(), b.rend()) + a;
    }
};