class Solution {
public:
    string simplifyPath(string path) {
        string answer;
        
        for(int p1 = 0, p2 = 1; p1 < path.length(); p1 = p2){
            p2 = path.find("/", p1 + 1);
            if(p2 == string::npos){
                p2 = path.length();
            }
            
            if(p1 + 1 < p2){
                string dir_name = path.substr(p1 + 1, p2 - p1 - 1);
                if(dir_name == "."){
                    continue;
                }else if(dir_name == ".."){
                    while(!answer.empty() && answer.back() != '/'){
                        answer.pop_back();
                    }
                    if(!answer.empty()){
                        answer.pop_back();
                    }
                }else{
                    answer += "/" + dir_name;
                }
            }
        }
        
        if(answer.empty() && !path.empty()){
            answer = "/";
        }
        
        return answer;
    }
};