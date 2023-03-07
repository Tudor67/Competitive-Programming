class Solution {
public:
    int compress(vector<char>& chars) {
        const int N = chars.size();

        int len = 0;
        int l = 0;
        while(l < N){
            // fix the current char
            len += 1;
            chars[len - 1] = chars[l];
            
            // find the last consecutive repeating char of the current group
            int r = l;
            while(r + 1 < N && chars[l] == chars[r + 1]){
                r += 1;
            }

            // compute the group len and update the chars vector if necessary
            int groupLen = r - l + 1;
            if(groupLen >= 2){
                int numStartPos = len;
                while(groupLen > 0){
                    len += 1;
                    chars[len - 1] = char('0' + (groupLen % 10));
                    groupLen /= 10;
                }
                reverse(chars.begin() + numStartPos, chars.begin() + len);
            }

            l = r + 1;
        }

        return len;
    }
};