class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        
        vector<int> p(4);
        iota(p.begin(), p.end(), 0);
        
        int answer = 1e9;
        do{
            int num1 = (s[p[0]] - '0') * 10 + s[p[1]] - '0';
            int num2 = (s[p[2]] - '0') * 10 + s[p[3]] - '0';
            answer = min(answer, num1 + num2);
        }while(next_permutation(p.begin(), p.end()));
        
        return answer;
    }
};