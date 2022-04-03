//
// Created by wangyu980312 on 15/03/2022.
//

#ifndef TD_4_FIFO_H
#define TD_4_FIFO_H

#include <exception>
#include <queue>
#include "Mutex.h"

template <typename T>
class Fifo
{
public:
    // Exception if the fifo is empty
    class EmptyException : std::exception
    {
    public:
        const char* throwException() const noexcept;
    };

    // Add an element at the end of queue
    void push(T element);

    // Remove the element at the beginning of the queue
    T pop();

    // Remove the element at the beginning of the queue with a timeout
    T pop(double timeout_ms) noexcept(false);

private:
    // The queue
    std::queue<T> elements;

    // Mutex object
    Mutex mutex;
};

template<typename T>
void Fifo<T>::push(T element)
{
    Mutex::Lock lock(mutex);
    elements.push(element);
    lock.notifyAll();
    lock.~Lock();
}

template<typename T>
T Fifo<T>::pop()
{
    Mutex::Lock lock(mutex);
    if (elements.empty())
    {
        lock.wait();
        lock.notifyAll();
        lock.~Lock();
    }
    else
    {
        T popped = elements.front();
        elements.pop();
        lock.notifyAll();
        lock.~Lock();
        return popped;
    }
}

template<typename T>
T Fifo<T>::pop(double timeout_ms) noexcept(false)
{
    Mutex::Lock lock(mutex);
    if (elements.empty())
    {
        lock.wait(timeout_ms);
        lock.notifyAll();
        lock.~Lock();
        throw Fifo<T>::EmptyException();
    }
    else
    {
        T popped = elements.front();
        elements.pop();
        lock.notify();
        lock.~Lock();
        return popped;
    }
}

template<typename T>
const char *Fifo<T>::EmptyException::throwException() const noexcept
{
    return "Empty exception!";
}

#endif //TD_4_FIFO_H
