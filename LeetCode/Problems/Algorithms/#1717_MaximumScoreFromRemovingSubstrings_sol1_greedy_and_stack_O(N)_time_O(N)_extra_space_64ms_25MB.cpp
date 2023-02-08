class Solution {
private:
    void remove(string& s, char a, char b, int operationGain, int& totalGain){
        string st;
        for(char c: s){
            if(!st.empty() && st.back() == a && c == b){
                st.pop_back();
                totalGain += operationGain;
            }else{
                st += c;
            }
        }
        s = st;
    }

public:
    int maximumGain(string s, int x, int y) {
        int maxGain = 0;
        if(x >= y){
            remove(s, 'a', 'b', x, maxGain);
            remove(s, 'b', 'a', y, maxGain);
        }else{
            remove(s, 'b', 'a', y, maxGain);
            remove(s, 'a', 'b', x, maxGain);
        }
        return maxGain;
    }
};