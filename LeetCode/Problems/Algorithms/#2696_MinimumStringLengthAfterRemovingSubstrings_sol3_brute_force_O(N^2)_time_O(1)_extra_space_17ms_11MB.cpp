class Solution {
public:
    int minLength(string s) {
        static const vector<string> STRINGS_TO_REMOVE = {"AB", "CD"};

        bool updated = true;
        while(updated){
            updated = false;
            for(const string& STR: STRINGS_TO_REMOVE){
                size_t pos = s.find(STR);
                if(pos != string::npos){
                    s.erase(pos, STR.length());
                    updated = true;
                }
            }
        }

        return s.length();
    }
};