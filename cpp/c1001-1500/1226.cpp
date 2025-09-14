class DiningPhilosophers {
    private:
        vector<mutex> forks;
        mutex table; 
        
    public:
        DiningPhilosophers() : forks(5) {}
        
        void wantsToEat(int philosopher,
                        function<void()> pickLeftFork,
                        function<void()> pickRightFork,
                        function<void()> eat,
                        function<void()> putLeftFork,
                        function<void()> putRightFork) {
            
            int left = philosopher;
            int right = (philosopher + 1) % 5;
            
            if (philosopher % 2 == 0) {
                scoped_lock lock(forks[left], forks[right]);
                pickLeftFork();
                pickRightFork();
                eat();
                putLeftFork();
                putRightFork();
            } else {
                scoped_lock lock(forks[right], forks[left]);
                pickRightFork();
                pickLeftFork();
                eat();
                putLeftFork();
                putRightFork();
            }
        }
    };