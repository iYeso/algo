/**
 * Created by Liam Huang (Liam0205) on 2018/10/10.
 */

#ifndef QUEUE_ARRAY_QUEUE_HPP_
#define QUEUE_ARRAY_QUEUE_HPP_

template <typename T>
class ArrayQueue {
  private:
    T*     items_    = nullptr;
    size_t capacity_ = 0;
    size_t head_     = 0;
    size_t tail_     = 0;

  public:
    ArrayQueue() = default;
    ArrayQueue(size_t capacity) : capacity_(capacity) {
        items_ = new T[capacity];
    }
    ~ArrayQueue() {
        if (nullptr != items_) {
            delete[] items_;
            items_ = nullptr;
        }
    }
    ArrayQueue(const ArrayQueue& other) : capacity_(other.capacity_) {
        items_ = new T[capacity_];
        for (size_t i = other.head_; i != other.tail_; ++i) {
            enqueue(other.items_[i]);
        }
    }
    ArrayQueue& operator=(const ArrayQueue& rhs) {
        delete[] items_;
        head_     = 0;
        tail_     = 0;
        capacity_ = rhs.capacity_;
        items_    = new T[capacity_];
        for (size_t i = other.head_; i != other.tail_; ++i) {
            enqueue(other.items_[i]);
        }
        return *this;
    }
    ArrayQueue(ArrayQueue&& other) : items_(other.items_),
                                     capacity_(other.capacity_),
                                     head_(other.head_),
                                     tail_(other.tail_) {
        other.items_    = nullptr;
        other.capacity_ = 0;
        other.head_     = 0;
        other.tail_     = 0;
    }
    ArrayQueue& operator=(ArrayQueue&& rhs) {
        delete[] items_;
        items_        = rhs.items_;
        capacity_     = rhs.capacity_;
        head_         = rhs.head_;
        tail_         = rhs.tail_;
        rhs.items_    = nullptr;
        rhs.capacity_ = 0;
        rhs.head_     = 0;
        rhs.tail_     = 0;
        return *this;
    }
};

#endif  // QUEUE_ARRAY_QUEUE_HPP_
