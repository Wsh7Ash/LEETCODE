class H2O {
    private:
        mutex mtx;
        condition_variable cv;
        int h_count;
        int o_count;
    public:
        H2O() {
            h_count = 0;
            o_count = 0;
        }
    
        void hydrogen(function<void()> releaseHydrogen) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {return h_count < 2; });
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();
            h_count++;
            if(h_count == 2 && o_count == 1){
                h_count = 0;
                o_count = 0;
                cv.notify_all();
            }
        }
    
        void oxygen(function<void()> releaseOxygen) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {return o_count < 1; });
            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();
            o_count++;
            if(h_count == 2 && o_count == 1){
                h_count = 0;
                o_count = 0;
                cv.notify_all();
            }
        }
    };