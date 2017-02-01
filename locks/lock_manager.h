#ifndef LOCK_MANAGER_H
#define LOCK_MANAGER_H

#include "read_write_lock.h"
#include <map>
#include <mutex>
#include <memory>

class Lock_Manager {
  std::mutex m;
  std::map<int, std::unique_ptr<Read_Write_Lock>> lock_table;
  std::map<int, int> lock_counters;
  void createLock(int);
  void deleteLock(int);
  public:
  void read_lock(int);
  void read_unlock(int);
  void write_lock(int);
  void write_unlock(int);
};

#endif
