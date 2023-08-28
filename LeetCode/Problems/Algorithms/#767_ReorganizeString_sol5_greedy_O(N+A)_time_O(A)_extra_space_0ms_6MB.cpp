class Solution {
public:
    string reorganizeString(string s) {
        const int N = s.length();

        char mostFreqChar = s[0];
        unordered_map<char, int> count;
        for(char c: s){
            count[c] += 1;
            if(count[mostFreqChar] < count[c]){
                mostFreqChar = c;
            }
        }

        if(count[mostFreqChar] > (N + 1) / 2){
            return "";
        }

        string res(N, '.');
        int index = 0;
        while(count[mostFreqChar] > 0){
            res[index] = mostFreqChar;
            index += 2;
            count[mostFreqChar] -= 1;
        }

        count.erase(mostFreqChar);
        for(const pair<char, int>& P: count){
            char c = P.first;
            while(count[c] > 0){
                if(index >= N){
                    index = 1;
                }
                res[index] = c;
                index += 2;
                count[c] -= 1;
            }
        }

        return res;
    }
};