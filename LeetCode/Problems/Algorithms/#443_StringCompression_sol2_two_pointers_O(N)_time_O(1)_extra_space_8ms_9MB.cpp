class Solution {
public:
    int compress(vector<char>& chars) {
        const int N = chars.size();
        
        int i = 0;
        int j = 0;
        while(j < N){
            char currentChar = chars[j];
            int count = 1;
            while(j + count < N && currentChar == chars[j + count]){
                count += 1;
            }
            
            chars[i] = currentChar;
            i += 1;
            if(count >= 2){
                string s = to_string(count);
                copy(s.begin(), s.end(), chars.begin() + i);
                i += s.length();
            }
            
            j += count;
        }
        
        return i;
    }
};