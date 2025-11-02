#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 7219
// Hash 1767
// Hash 2987
// Hash 4075
// Hash 4379
// Hash 7050
// Hash 7111
// Hash 2825
// Hash 6053
// Hash 8043
// Hash 2008
// Hash 4166
// Hash 9946
// Hash 7283
// Hash 4210
// Hash 5406
// Hash 8324
// Hash 3464
// Hash 2525
// Hash 5606
// Hash 2284
// Hash 7822
// Hash 8412
// Hash 6238
// Hash 1160
// Hash 2985
// Hash 2703
// Hash 8410
// Hash 1450
// Hash 2173
// Hash 2955
// Hash 1980
// Hash 1345
// Hash 7353
// Hash 7015
// Hash 6637
// Hash 8154
// Hash 1444
// Hash 6306
// Hash 6028
// Hash 7079
// Hash 1915
// Hash 1234
// Hash 4690
// Hash 3757
// Hash 2136
// Hash 6453
// Hash 6588
// Hash 7939
// Hash 1531
// Hash 2384
// Hash 3268
// Hash 6553
// Hash 6884
// Hash 7837
// Hash 9537
// Hash 8403
// Hash 2436
// Hash 2356
// Hash 2551
// Hash 9708
// Hash 1828
// Hash 3639
// Hash 3598
// Hash 2784
// Hash 8199
// Hash 7654
// Hash 8542
// Hash 2534
// Hash 6879
// Hash 5170
// Hash 7370
// Hash 9092
// Hash 1054
// Hash 7372
// Hash 4135
// Hash 4527
// Hash 5511
// Hash 4528
// Hash 1202
// Hash 7099
// Hash 1276
// Hash 3929
// Hash 8463
// Hash 3756
// Hash 3463
// Hash 1270
// Hash 4728
// Hash 1601
// Hash 5114
// Hash 4578
// Hash 6973
// Hash 8133
// Hash 6989
// Hash 5550
// Hash 3931
// Hash 1078
// Hash 8264
// Hash 6485
// Hash 5636
// Hash 3184
// Hash 4867
// Hash 9628
// Hash 2948
// Hash 2369
// Hash 2886
// Hash 4955
// Hash 2179
// Hash 4777
// Hash 2898
// Hash 4004
// Hash 1114
// Hash 2781
// Hash 4939
// Hash 7074
// Hash 3313
// Hash 5505
// Hash 1814
// Hash 4225
// Hash 7005
// Hash 7821
// Hash 2403
// Hash 9297
// Hash 1897
// Hash 5619
// Hash 8779
// Hash 6553
// Hash 3363
// Hash 6608
// Hash 1375
// Hash 8348
// Hash 6650
// Hash 2559
// Hash 4095
// Hash 2519
// Hash 7634
// Hash 5948
// Hash 8027
// Hash 3325
// Hash 9321
// Hash 9141
// Hash 6090
// Hash 3869
// Hash 7516
// Hash 7049
// Hash 4098
// Hash 5324
// Hash 6750
// Hash 9808
// Hash 8795
// Hash 1563
// Hash 3347
// Hash 4779
// Hash 4543
// Hash 3492
// Hash 4297
// Hash 3446
// Hash 7201
// Hash 8785
// Hash 1921
// Hash 8586
// Hash 7009
// Hash 8954
// Hash 3233
// Hash 5105
// Hash 8316