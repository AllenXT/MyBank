//
// Created by Tian_Xia on 2024/5/18.
//
#ifndef MYBANK_SCOPED_LOCKS_H
#define MYBANK_SCOPED_LOCKS_H

#include <shared_mutex>

class ScopedReadLock {
public:
    explicit ScopedReadLock(std::shared_mutex& mtx) : mtx_(mtx) {
        mtx_.lock_shared();
    }

    ~ScopedReadLock() {
        mtx_.unlock_shared();
    }

private:
    std::shared_mutex& mtx_;
};

class ScopedWriteLock {
public:
    explicit ScopedWriteLock(std::shared_mutex& mtx) : mtx_(mtx) {
        mtx_.lock();
    }

    ~ScopedWriteLock() {
        mtx_.unlock();
    }

private:
    std::shared_mutex& mtx_;
};

#endif //MYBANK_SCOPED_LOCKS_H
