class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> intFrom = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        const int N = s.length();
        
        int answer = 0;
        for(int i = 0; i < N; ++i){
            answer += intFrom[s[i]];
        }
        
        for(int i = 0; i + 1 < N; ++i){
            if(intFrom[s[i]] < intFrom[s[i + 1]]){
                answer -= 2 * intFrom[s[i]];
            }
        }
        
        return answer;
    }
};