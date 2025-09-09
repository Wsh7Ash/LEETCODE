class Solution {
    private:
        bool isLeap(int year){
            if(year % 4 != 0) return false;
            else if(year % 100 != 0) return true;
            else return year % 400 == 0;
        }
    public:
        string dayOfTheWeek(int day, int month, int year) {
            vector<string> weekdays = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    
            vector<int> months = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
            int totalDays = 0;
            for(int y = 1971; y < year; y++) totalDays += isLeap(y) ? 366 : 365;
    
            for(int m = 1; m < month; m++){
                totalDays += months[m];
                if(m == 2 && isLeap(year)){
                    totalDays += 1;
                }
            }
    
            totalDays += day - 1;
    
            return weekdays[totalDays % 7];
        }
    };