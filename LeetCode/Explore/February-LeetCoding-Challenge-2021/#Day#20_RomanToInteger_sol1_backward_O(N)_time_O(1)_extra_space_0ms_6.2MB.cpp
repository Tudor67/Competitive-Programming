class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> intFrom = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        const int N = s.length();
        int answer = intFrom[s[N - 1]];
        for(int i = N - 2; i >= 0; --i){
            if(intFrom[s[i]] < intFrom[s[i + 1]]){
                answer -= intFrom[s[i]];
            }else{
                answer += intFrom[s[i]];
            }
        }
        return answer;
    }
};