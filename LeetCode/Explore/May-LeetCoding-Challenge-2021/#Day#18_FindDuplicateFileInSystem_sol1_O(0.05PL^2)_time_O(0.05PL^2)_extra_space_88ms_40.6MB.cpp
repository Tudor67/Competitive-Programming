class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> groupOf;
        for(const string& PATH: paths){
            const int PATH_LEN = PATH.length();
            int spacePos = PATH.find(' ');
            string dirName = PATH.substr(0, spacePos);
            
            while(spacePos != PATH_LEN){
                int nextSpacePos = PATH.find(' ', spacePos + 1);
                if(nextSpacePos == string::npos){
                    nextSpacePos = PATH_LEN;
                }
                string fullFileName = PATH.substr(spacePos + 1, nextSpacePos - spacePos - 1);
                int openParPos = fullFileName.find('(');
                string fileName = fullFileName.substr(0, openParPos);
                string contentName = fullFileName.substr(openParPos);
                groupOf[contentName].push_back(dirName + "/" + fileName);
                spacePos = nextSpacePos;
            }
        }
        
        vector<vector<string>> answer;
        for(const pair<string, vector<string>>& P: groupOf){
            if((int)P.second.size() >= 2){
                answer.push_back(P.second);
            }
        }
        
        return answer;
    }
};