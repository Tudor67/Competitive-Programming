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
                for(int j = 0; j < LEN2; ++j){
                    if(res[i + j] != str2[j] && isFixed[i + j]){
                        return "";
                    }else{
                        res[i + j] = str2[j];
                        isFixed[i + j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < LEN1; ++i){
            if(str1[i] == 'F' && equal(str2.begin(), str2.end(), res.begin() + i)){
                bool changed = false;
                for(int j = LEN2 - 1; j >= 0; --j){
                    if(!isFixed[i + j]){
                        res[i + j] = 'b';
                        isFixed[i + j] = true;
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