#include "lock_manager.h"

void Lock_Manager::createLock(int inode) {
  std::unique_lock<std::mutex> lock(m);
  if (lock_counters.count(inode) == 0 || lock_counters.at(inode) == 0) {
    lock_table[inode] = std::make_unique<ReadWriteLock>();
    lock_counters[inode] = 0;
  }
  lock_counters[inode]++;
}

void Lock_Manager::deleteLock(int inode) {
  std::unique_lock<std::mutex> lock(m);
  lock_counters[inode]--;
  if (lock_counters.at(inode) == 0) {
    lock_table.erase(inode);
  }
}

void Lock_Manger::read_lock(int inode) {
  createLock(inode);
  lock_table[inode]->read_lock();
}

void Lock_Manger::read_unlock(int inode) {
  lock_table[inode]->read_unlock();
  deleteLock(inode);
}

void Lock_Manger::write_lock(int inode) {
  createLock(inode);
  lock_table[inode]->write_lock();
}

void Lock_Manger::write_unlock(int inode) {
  lock_table[inode]->write_unlock();
  deleteLock(inode);
}
