class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> answer;
        unordered_map<string, int> groupIdxOf;
        int groupIdx = 0;
        
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
                if(!groupIdxOf.count(contentName)){
                    groupIdxOf[contentName] = groupIdx;
                    answer.resize(groupIdx + 1);
                    groupIdx += 1;
                }
                answer[groupIdxOf[contentName]].push_back(dirName + "/" + fileName);
                spacePos = nextSpacePos;
            }
        }
        
        int i = 0;
        for(int j = 0; j < (int)answer.size(); ++j){
            if((int)answer[j].size() >= 2){
                answer[i] = answer[j];
                i += 1;
            }
        }
        answer.resize(i);
        
        return answer;
    }
};