#ifndef _SPIN_LOCK_TXN_MANAGER_H_
#define _SPIN_LOCK_TXN_MANAGER_H_

#include <iostream>
#include <set>

#include "TxnManager.h"
 
class SpinLockTxnManager : public TxnManager {
public:
    SpinLockTxnManager(std::unordered_map<long,std::string> *table,
		       bool _dynamic)
	: TxnManager(table),
	  dynamic(_dynamic) {}
    virtual bool RunTxn(const std::vector<OpDescription> &operations,
            std::vector<string> *get_results);

private:
    unordered_map<long, atomic_flag> lockTable;
    // Prevents concurrent insertions to the lock table.
    mutex tableMutex;
    bool dynamic;
};

#endif /* _SPIN_LOCK_TXN_MANAGER_H_ */
