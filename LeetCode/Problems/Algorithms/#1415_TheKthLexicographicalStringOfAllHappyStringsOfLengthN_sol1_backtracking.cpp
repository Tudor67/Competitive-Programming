class Solution {
private:
    void back(int stack_size, string& st, const int& n, const int& k, int& cnt, string& answer){
        if(stack_size == n){
            ++cnt;
            if(cnt == k){
                answer = st;
            }
        }else{
            for(char c: {'a', 'b', 'c'}){
                if(answer.empty()){
                    if(stack_size == 0 || (stack_size > 0 && st[stack_size - 1] != c)){
                        st[stack_size] = c;
                        back(stack_size + 1, st, n, k, cnt, answer);
                    }
                }else{
                    break;
                }
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        string answer;
        if(k <= 3 * (1 << (n - 1))){
            string st(n, '.');
            int cnt = 0;
            back(0, st, n, k, cnt, answer);
        }
        return answer;
    }
};