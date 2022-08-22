class ZeroEvenOdd {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int turn = 0;
    int i = 1;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock<mutex> lock(m);
            while(turn!=0 and i<=n){
                cv.wait(lock);
            }
            if(i>n)
                break;
            printNumber(0);
                
            turn = (i%2==0 ? 2 : 1);
            cv.notify_all();
        }
        return ;
    }

    void even(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock<mutex> lock(m);

            while(turn!=2 and i<=n)
            {
                cv.wait(lock);
            }
            if(i>n)
                break;
            printNumber(i++);
            turn = 0;
            cv.notify_all();
        }
        return ;
    }

    void odd(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock<mutex> lock(m);
            // cv.wait(lk, [this]{return !turn && i % 2 != 0;});
            while(turn!=1 and i<=n)
            {
                cv.wait(lock);
            }
            if(i>n)
                break;
            printNumber(i++);
            turn = 0;
            cv.notify_all();
        }
        return ;
    }
};