class Solution {
private:
    void addOne(string& s){
        int i = (int)s.length() - 1;
        while(i >= 0 && s[i] == '1'){
            s[i] = '0';
            i -= 1;
        }

        if(i >= 0){
            s[i] = '1';
        }else{
            s.insert(s.begin(), '1');
        }
    }

public:
    int numSteps(string s) {
        int steps = 0;
        while((int)s.length() > 1){
            steps += 1;
            if(s.back() == '0'){
                s.pop_back();
            }else{
                addOne(s);
            }
        }
        return steps;
    }
};