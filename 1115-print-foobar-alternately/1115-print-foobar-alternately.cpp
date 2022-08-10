class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn = true;  // is it foo's turn to run?

public:
    FooBar(int n) {
        this->n = n;
        
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            while(fooTurn==false){
                cv.wait(lock);
            }
			
        	printFoo();
			
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            while(fooTurn){
                cv.wait(lock);
            }
			
        	printBar();
			
            fooTurn = true;
            cv.notify_one();
        }
    }
};