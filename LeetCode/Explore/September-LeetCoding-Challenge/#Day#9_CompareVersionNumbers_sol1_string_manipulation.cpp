class Solution {
public:
    int compareVersion(string version1, string version2) {
        int answer = 0;
        int dots = max(count(version1.begin(), version1.end(), '.'),
                       count(version2.begin(), version2.end(), '.'));
        
        size_t start1 = 0;
        size_t start2 = 0;
        for(int iteration = 1; iteration <= dots + 1; ++iteration){
            size_t end1 = version1.find('.', start1 + 1);
            size_t end2 = version2.find('.', start2 + 1);
            
            int num1 = (start1 == version1.length() ? 0 : stoi(version1.substr(start1, end1 - start1)));
            int num2 = (start2 == version2.length() ? 0 : stoi(version2.substr(start2, end2 - start2)));
            
            if(num1 < num2){
                answer = -1;
                break;
            }else if(num1 > num2){
                answer = 1;
                break;
            }
            
            start1 = (end1 == string::npos ? version1.length() : end1 + 1);
            start2 = (end2 == string::npos ? version2.length() : end2 + 1);
        }
        
        return answer;
    }
};