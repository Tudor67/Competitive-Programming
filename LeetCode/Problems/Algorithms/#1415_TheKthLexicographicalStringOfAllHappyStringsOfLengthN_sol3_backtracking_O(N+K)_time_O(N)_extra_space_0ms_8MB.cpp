class Solution {
private:
    void search(int index, string& st, int& k, string& res){
        if(!res.empty()){
            // stop
        }else if(index == (int)st.length()){
            k -= 1;
            if(k == 0){
                res = st;
            }
        }else{
            for(char c = 'a'; c <= 'c'; ++c){
                if(index == 0 || st[index - 1] != c){
                    st[index] = c;
                    search(index + 1, st, k, res);
                }
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        string st(n, 'a');
        string res;
        search(0, st, k, res);
        return res;
    }
};