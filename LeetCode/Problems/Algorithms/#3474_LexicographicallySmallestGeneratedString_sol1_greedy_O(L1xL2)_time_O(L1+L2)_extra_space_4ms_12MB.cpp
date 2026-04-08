class Solution {
public:
    string generateString(string str1, string str2) {
        const int LEN1 = str1.length();
        const int LEN2 = str2.length();
        const int N = LEN1 + LEN2 - 1;

        string res(N, 'a');
        vector<bool> isFixed(N, false);
        for(int i = 0; i < LEN1; ++i){
            if(str1[i] == 'T'){
                copy(str2.begin(), str2.end(), res.begin() + i);
                fill(isFixed.begin() + i, isFixed.begin() + i + LEN2, true);
            }
        }

        for(int i = 0; i < LEN1; ++i){
            int comp = res.compare(i, LEN2, str2, 0, LEN2);
            if(str1[i] == 'T' && comp != 0){
                return "";
            }
            if(str1[i] == 'F' && comp == 0){
                bool changed = false;
                for(int j = i + LEN2 - 1; j >= i; --j){
                    if(!isFixed[j]){
                        res[j] = 'b';
                        isFixed[j] = true;
                        changed = true;
                        break;
                    }
                }
                if(!changed){
                    return "";
                }
            }
        }

        return res;
    }
};