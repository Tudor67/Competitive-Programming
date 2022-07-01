class Solution {
private:
    int getCharType(char c){
        if(islower(c)){
            return 0;
        }else if(isupper(c)){
            return 1;
        }else if(isdigit(c)){
            return 2;
        }
        return 3;
    }
    
public:
    int strongPasswordChecker(string password) {        
        // Step 1: if (password.length() < 6):
        //            there are three special cases
        //            we can always destroy a group of 3 consecutive repeating chars with 1 insert operation
        bool containsLower = false;
        bool containsUpper = false;
        bool containsDigit = false;
        for(char c: password){
            if(islower(c)){
                containsLower = true;
            }else if(isupper(c)){
                containsUpper = true;
            }else if(isdigit(c)){
                containsDigit = true;
            }
        }
        
        if((int)password.length() <= 3){
            return 6 - (int)password.length();
        }
        
        if((int)password.length() == 4){
            return 2 + max(0, (int)(!containsLower) + (int)(!containsUpper) + (int)(!containsDigit) - 2);
        }
        
        if((int)password.length() == 5){
            return 1 + max(0, (int)(!containsLower) + (int)(!containsUpper) + (int)(!containsDigit) - 1);
        }
        
        // Step 2: if (password.length() > 20 &&
        //             there are groups of consecutive repeating chars, with groupSize >= 2):
        //            remove max (password.length() - 20) chars:
        //                   find groups of consecutive repeating chars such that groupSize >= 2
        //                   remove one char from groups:
        //                       groups with groupSize % 3 == 0 have the highest priority
        //                       groups with groupSize % 3 == 1
        //                       groups with groupSize % 3 == 2 have the lowest priority
        //                       in case of tie of (groupSize % 3): the largest groupSize has the highest priority
        //            maintain a heap with current groups of consecutive repeating chars after each remove operation
        int totalSteps = 0;
        using T3 = tuple<int, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        int groupStartIdx = 0;
        int groupSize = 0;
        for(int i = 0; i < (int)password.length(); ++i){
            if(password[groupStartIdx] == password[i]){
                groupSize += 1;
            }
            
            if(i + 1 == (int)password.length() || password[groupStartIdx] != password[i + 1]){
                if(groupSize >= 2){
                    minHeap.emplace(groupSize % 3, -groupSize, groupStartIdx);
                }
                groupStartIdx = i + 1;
                groupSize = 0;
            }
        }
        
        const int ERASED_CHAR = ' ';
        for(int step = 1; step <= (int)password.length() - 20 && !minHeap.empty(); ++step){
            int groupSize = -get<1>(minHeap.top());
            int groupStartIdx = get<2>(minHeap.top());
            minHeap.pop();
            
            password[groupStartIdx] = ERASED_CHAR;
            if(groupSize - 1 >= 2){
                minHeap.emplace((groupSize - 1) % 3, -(groupSize - 1), groupStartIdx + 1);
            }
            
            totalSteps += 1;
        }
        
        password.resize(remove(password.begin(), password.end(), ERASED_CHAR) - password.begin());
        
        // Step 3: if (password.length() > 20 &&
        //             there are no groups of consecutive repeating chars, with groupSize >= 2):
        //         remove (password.length() - 20) chars:
        //                remove char c if it is redundant or count[getCharType(c)] >= 2
        //                {'a', 'b', ... ,'z'} are considered a single char (a lowercase letter)
        //                {'A', 'B', ... ,'Z'} are considered a single char (an uppercase letter)
        //                {'0', '1', ... ,'9'} are considered a single char (a digit)
        //                {'.', '!'} are considered a single char (a redundant char)
        vector<int> count(5);
        for(char c: password){
            count[getCharType(c)] += 1;
        }
        
        int erasedChars = 0;
        for(int i = 0; i < (int)password.length() && (int)password.length() - erasedChars > 20; ++i){
            if(password[i] == '.' || password[i] == '!' || count[getCharType(password[i])] >= 2){
                count[getCharType(password[i])] -= 1;
                password[i] = ERASED_CHAR;
                erasedChars += 1;
                totalSteps += 1;
            }
        }
        
        password.resize(remove(password.begin(), password.end(), ERASED_CHAR) - password.begin());
        
        // Step 4: 6 <= password.length() <= 20
        //           destroy groups of 3 consecutive repeating chars
        //           by replacing the 3rd repeating char with a missing lowercase letter, uppercase letter or digit
        //           example: ..aaa.. -> ..aaA..
        for(int i = 2; i < (int)password.length(); ++i){
            if(password[i - 2] == password[i - 1] && password[i - 1] == password[i]){
                if(!containsLower){
                    password[i] = 'a';
                    containsLower = true;
                }else if(!containsUpper){
                    password[i] = 'A';
                    containsUpper = true;
                }else{
                    if(i + 1 < (int)password.length() && password[i + 1] == '9'){
                        password[i] = '8';
                    }else{
                        password[i] = '9';
                    }
                    containsDigit = true;
                }
                totalSteps += 1;
            }
        }
        
        // Step 5: 6 <= password.length() <= 20
        //           replace char c with missing lowercase letter, uppercase letter or digit
        //           (if and only if c is redundant or count[getCharType(c)] >= 2)
        //           example: . -> a
        totalSteps += (int)(!containsLower) + (int)(!containsUpper) + (int)(!containsDigit);
        
        return totalSteps;
    }
};