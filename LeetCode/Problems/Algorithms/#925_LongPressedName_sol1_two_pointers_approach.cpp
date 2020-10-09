class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while(i < name.length() && j < typed.length()){
            if(name[i] == typed[j]){
                i += 1;
            }else if(i == 0 || typed[j - 1] != typed[j]){
                break;
            }
            j += 1;
        }
        while(1 <= j && j < typed.length() && typed[j - 1] == typed[j]){
            j += 1;
        }
        return (i == name.length() && j == typed.length());
    }
};