class Solution {
public:
    string capitalizeTitle(string title) {
        const int N = title.length();
        
        int len = 0;
        for(int i = 0; i < N; ++i){
            if(title[i] != ' '){
                len += 1;
            }
            if(i + 1 == N || title[i + 1] == ' '){
                for(int j = i - len + 1; j <= i; ++j){
                    title[j] = tolower(title[j]);
                }
                if(len >= 3){
                    title[i - len + 1] = toupper(title[i - len + 1]);
                }
                len = 0;
            }
        }
        
        return title;
    }
};