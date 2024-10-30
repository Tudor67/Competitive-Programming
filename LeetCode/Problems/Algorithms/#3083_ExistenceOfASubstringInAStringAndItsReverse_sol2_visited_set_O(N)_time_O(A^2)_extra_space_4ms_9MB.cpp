class Solution {
private:
    const int A = 26;
    const int FIRST_CHAR = 'a';

    int encode(char a, char b){
        return (a - FIRST_CHAR) * A + (b - FIRST_CHAR);
    }

public:
    bool isSubstringPresent(string s) {
        const int N = s.length();

        set<int> vis;
        for(int i = 0; i + 1 < N; ++i){
            vis.insert(encode(s[i], s[i + 1]));
        }
        
        for(int i = 0; i + 1 < N; ++i){
            if(vis.count(encode(s[i + 1], s[i]))){
                return true;
            }
        }
        
        return false;
    }
};