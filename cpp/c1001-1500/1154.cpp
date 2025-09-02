class Solution {
    private:
        bool isLeapYear(int year){
            if(year % 4 != 0){
                return false;
            }else if(year % 100 != 0){
                return true;
            }else {
                return year % 400 == 0;
            }
        }
    public:
        int dayOfYear(string date) {
            
            int year = stoi(date.substr(0, 4));
            int month = stoi(date.substr(5, 2));
            int day = stoi(date.substr(8, 2));
    
            vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
            if(isLeapYear(year)) daysInMonth[1] = 29;
    
            int dayOfyear = 0;
            for(int i = 0; i < month - 1; i++) dayOfyear += daysInMonth[i];
            dayOfyear += day;
    
            return dayOfyear;
        }
    };