class ZeroEvenOdd {
    private:
        int n;
        mutex mtx;
        condition_variable cv;
        int state;
        int cur;
    
    public:
        ZeroEvenOdd(int n) {
            this->n = n;
            state = 0;
            cur = 1;
        }
    
        // printNumber(x) outputs "x", where x is an integer.
        void zero(function<void(int)> printNumber) {
            for(int i = 0; i < n; i++){
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [this]{return state == 0;});
                printNumber(0);
                if(cur % 2 == 1) state = 1;
                else state = 2;
                cv.notify_all();
            }
        }
    
        void even(function<void(int)> printNumber) {
            for(int i = 0; i < n / 2; i++){
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [this]{return state == 2;});
                printNumber(cur);
                cur++;
                state=0;
                cv.notify_all();
            }
        }
    
        void odd(function<void(int)> printNumber) {
            for(int i = 0; i < (n+1)/2; i++){
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [this]{return state == 1;});
                printNumber(cur);
                cur++;
                state=0;
                cv.notify_all();
            }
        }
    };