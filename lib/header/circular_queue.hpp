#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#define QUEUE_GROWTH_RATE 4

#include <iomanip>
#include <iostream>
#include <cstddef>

template<typename T>
class CircularQueue {

// --- Attributes ---
private:
    T  null_el;
    T* queue_array;
    size_t size, front, back;
    bool full, empty;


// --- Initialization ---
public:
    ~CircularQueue() { delete[] queue_array; }
    CircularQueue(size_t initial_size, T el)
    :null_el(el),
     size(initial_size),
     front(0),
     back(0),
     full(false),
     empty(true)
    {
        if (size < 1) { size = 1; }

        void* array_ptr = operator new[](size * sizeof(T));
        queue_array = static_cast<T*>(array_ptr);
    }

    size_t getSize() { return size; }


// --- Operations ---
public:
    void enqueue(T el) {
        if (!full) {
            queue_array[front] = el;
            front = (++front)%size;

            if (front == back) {
                full = true;
            }

            empty = false;
        } else {
            increaseSize(QUEUE_GROWTH_RATE);
            enqueue(el);
        }
    }

    T dequeue() {
        T output;

        if (!empty) {
            output = queue_array[back];
            back   = (++back)%size;

            if (front == back) {
                empty = true;
            }

            full = false;
            return output;
        } else {
            return null_el;
        }
    }

    T& current();


// --- Internal Methods ---
private:
    void increaseSize(size_t size_increase) {
        if (size_increase < 1) { size_increase = 1; }
        
        void* array_ptr    = operator new[]((size+size_increase)*sizeof(T));
        T* new_queue_array = static_cast<T*>(array_ptr);

        size_t first_chunk_size  = size - back;
        size_t second_chunk_size = back;
        std::memcpy(new_queue_array, queue_array+back, first_chunk_size*sizeof(T));
        std::memcpy(new_queue_array+first_chunk_size, queue_array, second_chunk_size*sizeof(T));
        delete[] queue_array;
        queue_array = new_queue_array;

        back  = 0;
        front = size;
        size  = size + size_increase;
        full  = false;
    }


// --- Debug ---
public:
    T debugNullEl() {
        return null_el;
    }

    T debugGetElement(size_t place) {
        return queue_array[place];
    }

    void debug(bool should_print=false) {
        bool is_place_full = false;
        if (front < back || full) {
            is_place_full = true;
        }

        int char_num = std::to_string(size).length();
        for (int i=0; i<size; i++) {
            std::cout << std::setw(char_num) << i;
            std::cout << " ";

            if (i == back) {
                std::cout << "b";
            } else {
                std::cout << " ";
            }

            if (i == front) {
                std::cout << "f";
            } else {
                std::cout << " ";
            }
            std::cout << " : ";

            if (!(i==back) != !(i==front)) {
                is_place_full = !is_place_full;
            }

            if (is_place_full) {
                std::cout << "x";
            }

            std::cout << std::endl;
        }
    }

    void debugPrint() {
        for (int i=0; i<size; i++) {
            std::cout << queue_array[i] << std::endl;
        }
    }

};

#endif
