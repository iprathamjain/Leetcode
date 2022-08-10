class H2O {
    int d; // H - 2 * O
    std::mutex mtx;
    std::condition_variable cv;
    int turn = 0;
    
public:
    H2O(){
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<std::mutex> lock(mtx);
        while (turn == 2) {
            cv.wait(lock);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<std::mutex> lock(mtx);
        while (turn < 2) {
            cv.wait(lock);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn=0;
        cv.notify_all();
    }
};