class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> pathsFor;
        
        for(const string& PATH: paths){
            size_t spacePos = PATH.find(' ');
            string dirName = PATH.substr(0, spacePos);
            while(spacePos != string::npos){
                size_t nextSpacePos = PATH.find(' ', spacePos + 1);
                size_t len = (nextSpacePos == string::npos ? string::npos : nextSpacePos - spacePos - 1);
                string filenameWithContent = PATH.substr(spacePos + 1, len);
                size_t parenthesisPos = filenameWithContent.find('(');
                string filename = filenameWithContent.substr(0, parenthesisPos);
                string content = filenameWithContent.substr(parenthesisPos);
                pathsFor[content].push_back(dirName + "/" + filename);
                spacePos = nextSpacePos;
            }
        }
        
        vector<vector<string>> duplicates;
        for(const pair<string, vector<string>>& P: pathsFor){
            const vector<string>& PATHS = P.second;
            if((int)PATHS.size() >= 2){
                duplicates.push_back(PATHS);
            }
        }
        
        return duplicates;
    }
};