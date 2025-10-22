class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(string& opStr: operations){
            if(opStr[1] == '-'){
                res -= 1;
            }else{
                res += 1;
            }
        }
        return res;
    }
};