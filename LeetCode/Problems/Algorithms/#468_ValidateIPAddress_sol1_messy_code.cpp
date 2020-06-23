class Solution {
public:
    string validIPAddress(string IP) {
        // sanity check :)
        if(IP.length() > 39){
            return "Neither";
        }
        
        // IPv4 candidate
        int dots_cnt = count(IP.begin(), IP.end(), '.');
        if(dots_cnt == 3){
            int num = 0;
            int digit_cnt = 0;
            bool is_first_digit_of_num = true;
            
            for(int i = 0; i < IP.size(); ++i){
                if(isdigit(IP[i])){
                    num = 10 * num + IP[i] - '0';
                    ++digit_cnt;
                }else if(IP[i] != '.'){
                    return "Neither";
                }
                
                if(is_first_digit_of_num && i + 1 < IP.size() && IP[i] == '0' && IP[i + 1] != '.'){
                    return "Neither";
                }
                
                if(IP[i] == '.' || i + 1 == IP.size()){
                    if(IP[i] == '.' && i + 1 == IP.size()){
                        return "Neither";
                    }
                    
                    if(num <= 255 && digit_cnt >= 1 && digit_cnt <= 3){
                        num = 0;
                        digit_cnt = 0;
                        is_first_digit_of_num = true;
                    }else{
                        return "Neither";
                    }
                }else{
                    is_first_digit_of_num = false;
                }
            }
            
            return "IPv4";
        }
        
        // IPv6 candidate
        int colons_cnt = count(IP.begin(), IP.end(), ':');
        if(colons_cnt == 7){
            int num = 0;
            int digit_cnt = 0;
            
            for(int i = 0; i < IP.size(); ++i){
                bool is_valid_char = isdigit(IP[i]) || IP[i] == ':' ||
                                     ('a' <= tolower(IP[i]) && tolower(IP[i]) <= 'f');
                if(!is_valid_char){
                    return "Neither";
                }
                
                if(IP[i] != ':'){
                    num = 16 * num + tolower(IP[i]) - (isdigit(IP[i]) ? '0' : 'a' - 10);
                    ++digit_cnt;
                }
                
                if(IP[i] == ':' || i + 1 == IP.size()){
                    if(num >= (1 << 16) || digit_cnt == 0 || digit_cnt >= 5){
                        return "Neither";
                    }else{
                        num = 0;
                        digit_cnt = 0;
                    }
                }
            }
            
            return "IPv6";
        }
        
        return "Neither";
    }
};