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
            j += count;
            
            chars[i] = currentChar;
            i += 1;
            if(count >= 2){
                int len = 0;
                while(count > 0){
                    chars[i + len] = char('0' + (count % 10));
                    count /= 10;
                    len += 1;
                }
                reverse(chars.begin() + i, chars.begin() + i + len);
                i += len;
            }
        }
        
        return i;
    }
};