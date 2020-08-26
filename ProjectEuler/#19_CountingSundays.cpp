#include <iostream>
#include <vector>
using namespace std;

bool is_leap_year(const int& YEAR){
    return ((YEAR % 4 == 0 && YEAR % 100 != 0) || YEAR % 400 == 0);
}

const vector<int> days_of_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int answer = 0;
    int current_day = 0; // "current_day" of the week: 1 - Monday, ... 7 - Sunday
    for(int year = 1900; year <= 2000; ++year){
        for(int month = 1; month <= 12; ++month){
            int max_day = days_of_month[month] + (month == 2 && is_leap_year(year));
            for(int day = 1; day <= max_day; ++day){ // "day" of the month: 1,2,3,... 28|29|30|31
                ++current_day;
                if(current_day == 7){ // Sunday
                    answer += (day == 1 && 1901 <= year && year <= 2000);
                }else if(current_day > 7){
                    current_day = 1; // Monday
                }
            }
        }
    }
    
    // 171
    cout << answer;
    return 0;
}