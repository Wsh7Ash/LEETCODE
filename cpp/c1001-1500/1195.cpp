class FizzBuzz {
    private:
        int n;
        int cur;
        std::mutex mtx;
        std::condition_variable cv;
    
    public:
        FizzBuzz(int n) {
            this->n = n;
            this->cur = 1;
        }
    
        // printFizz() outputs "fizz".
        void fizz(function<void()> printFizz) {
            while(true){
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this](){
                    return cur > n || (cur % 3 == 0 && cur % 5 != 0);
                });
    
                if(cur > n) break;
                printFizz();
                cur++;
                cv.notify_all();
            }
        }
    
        // printBuzz() outputs "buzz".
        void buzz(function<void()> printBuzz) {
            while(true){
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this](){
                    return cur > n || (cur % 5 == 0 && cur % 3 != 0);
                });
    
                if(cur > n) break;
                printBuzz();
                cur++;
                cv.notify_all();
            }
        }
    
        // printFizzBuzz() outputs "fizzbuzz".
        void fizzbuzz(function<void()> printFizzBuzz) {
            while(true){
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this](){
                    return cur > n || (cur % 3 == 0 && cur % 5 == 0);
                });
    
                if(cur > n) break;
                printFizzBuzz();
                cur++;
                cv.notify_all();
            }
        }
    
        // printNumber(x) outputs "x", where x is an integer.
        void number(function<void(int)> printNumber) {
            while(true){
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this](){
                    return cur > n || (cur % 3 != 0 && cur % 5 != 0);
                });
    
                if(cur > n) break;
                printNumber(cur);
                cur++;
                cv.notify_all();
            }
        }
    };