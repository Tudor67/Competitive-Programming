class Solution {
private:
    int computeGain(const string& S, char a, char b, int x, int y){
        int gain = 0;
        
        string st1;
        for(char ch: S){
            if(!st1.empty() && st1.back() == a && ch == b){
                gain += x;
                st1.pop_back();
            }else{
                st1.push_back(ch);
            }
        }

        string st2;
        for(char ch: st1){
            if(!st2.empty() && st2.back() == b && ch == a){
                gain += y;
                st2.pop_back();
            }else{
                st2.push_back(ch);
            }
        }

        return gain;
    }

public:
    int maximumGain(string s, int x, int y) {
        return max(computeGain(s, 'a', 'b', x, y),
                   computeGain(s, 'b', 'a', y, x));
    }
};