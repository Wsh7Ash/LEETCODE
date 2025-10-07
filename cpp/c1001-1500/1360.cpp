class Solution {
    private:
    
        vector<int> daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
    
        bool isLeapYear(int year){
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }
    
        int getDaysInMonth(int month, int year){
            if(month == 2 && isLeapYear(year)){
                return 29;
            }
            return daysInMonth[month - 1];
        }
    
        int dateToDays(int year, int month, int day){
            int days = 0;
            for(int y = 1971; y < year; y++){
                days += isLeapYear(y) ? 366 : 365;
            }
            for(int m = 1; m < month; m++){
                days += getDaysInMonth(m, year);
            }
    
            days += day;
            return days;
        }
    
        void parseDate(string date, int& year, int& month, int& day){
            year = stoi(date.substr(0,4));
            month = stoi(date.substr(5,2));
            day = stoi(date.substr(8,2));
        }
    
    public:
        int daysBetweenDates(string date1, string date2) {
            int y1,m1,d1;
            int y2,m2,d2;
    
            parseDate(date1,y1,m1,d1);
            parseD-ate(date2,y2,m2,d2);
    
            int days1 = dateToDays(y1,m1,d1);
            int days2 = dateToDays(y2,m2,d2);
    
            return abs(days2 - days1);
        }
    };