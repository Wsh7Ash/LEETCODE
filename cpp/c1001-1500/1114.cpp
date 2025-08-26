class Foo {
    private:
        mutex mtx;
        condition_variable cv1, cv2;
        bool firstDone = false;
        bool secondDone = false;
    public:
        Foo() {
        }
    
        void first(function<void()> printFirst) {
            unique_lock<mutex> lock(mtx);
            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();
            firstDone = true;
            cv1.notify_one();
        }
    
        void second(function<void()> printSecond) {
            unique_lock<mutex> lock(mtx);
            cv1.wait(lock, [this] {return firstDone; });
            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();
            secondDone = true;
            cv2.notify_one();
        }
    
        void third(function<void()> printThird) {
            unique_lock<mutex> lock(mtx);
            cv2.wait(lock, [this] {return secondDone; });
            // printThird() outputs "third". Do not change or remove this line.
            printThird();
        }
    };