#ifndef _RTM_TXN_MANAGER_H_
#define _RTM_TXN_MANAGER_H_

#include <iostream>
#include <set>

#include "TxnManager.h"       
#include "rtm.h"

class RTMTxnManager : public TxnManager {
public:
    RTMTxnManager(HashTable *table);

    virtual bool RunTxn(const std::vector<OpDescription> &operations,
            std::vector<string> *get_results);

    void getStats();

private:
    unordered_map<uint64_t, spinlock_t*> lockTable;
    // Prevents concurrent insertions to the lock table.

    static spinlock_t table_lock;
};


#endif /* _RTM_TXN_MANAGER_H_ */
