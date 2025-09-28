class Solution {
private:
    vector<int> stringToVector(const string& S){
        vector<int> v;

        int currIndex = 0;
        while(currIndex < (int)S.length()){
            size_t nextIndex = S.find('.', currIndex);
            if(nextIndex == string::npos){
                nextIndex = S.length();
            }
            v.push_back(stoi(S.substr(currIndex, nextIndex - currIndex)));
            currIndex = (int)nextIndex + 1;
        }

        while(!v.empty() && v.back() == 0){
            v.pop_back();
        }

        return v;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = stringToVector(version1);
        vector<int> v2 = stringToVector(version2);
        if(v1 < v2){
            return -1;
        }else if(v1 > v2){
            return 1;
        }
        return 0;
    }
};