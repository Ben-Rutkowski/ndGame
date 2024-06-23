#include "circular_queue.hpp"
#include "event_manager.hpp"
#include "logger.hpp"
#include "test_success.h"
static ndLogger program_log("program.log");

template<typename T>
void compareQueue(CircularQueue<T>& queue, std::vector<T> compare) {
    T      null_el = queue.debugNullEl();
    size_t size    = queue.getSize();
    bool   success = queue.getSize() == compare.size();

    for (int i=0; i<size; i++) {
        if ((compare[i] != null_el) && 
            (queue.debugGetElement(i) != compare[i])) 
        {
            success = false; 
            break;
        }
    }

    if (success) {
        ndLog(SUC, UNIT_Success); 
    } else {
        ndLog(SUC, UNIT_Failure);
    }
}

template<typename T>
void compareEl(T a, T b) {
    if (a == b) {
        ndLog(SUC, UNIT_Success);
    } else {
        ndLog(SUC, UNIT_Failure);
    }
}

int main() {
    CircularQueue<int> test_queue(5, 0);
    test_queue.enqueue(1);
    test_queue.enqueue(2);
    test_queue.enqueue(3);
    compareQueue(test_queue, {
        1, 2, 3, 0, 0
    });

    compareEl(test_queue.dequeue(), 1);
    compareEl(test_queue.dequeue(), 2);

    test_queue.enqueue(4);
    compareQueue(test_queue, {
        0, 0, 3, 4, 0
    });

    test_queue.enqueue(5);
    test_queue.enqueue(6);
    test_queue.enqueue(7);
    compareQueue(test_queue, {
        6, 7, 3, 4, 5
    });

    test_queue.enqueue(8);
    compareQueue(test_queue, {
        3, 4, 5, 6, 7, 8, 0, 0, 0
    });

    compareEl(test_queue.dequeue(), 3);
    compareEl(test_queue.dequeue(), 4);
    compareEl(test_queue.dequeue(), 5);
    compareEl(test_queue.dequeue(), 6);
    compareEl(test_queue.dequeue(), 7);
    compareEl(test_queue.dequeue(), 8);
    compareEl(test_queue.dequeue(), 0);
}
