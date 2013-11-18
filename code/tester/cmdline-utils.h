#ifndef _CMD_LINE_UTILS_H_
#define _CMD_LINE_UTILS_H_

#include <mutex>

#include "optionparser.h"

extern const int VALUE_LENGTH;
extern const int NUM_KEYS;
#define DEFAULT_SECONDS     10
#define DEFAULT_OPS_PER_TXN 10
#define HLE_NAME            "hle"
#define RTM_NAME            "rtm"
#define SPIN_NAME           "spin"
#define LOCK_TABLE_NAME     "tbl"

extern std::mutex global_cout_mutex;
extern int total_txns;

enum  optionIndex {UNKNOWN, HELP, NUM_THREADS, NUM_SECONDS, OPS_PER_TXN, RATIO};
extern const option::Descriptor usage[];

inline int getArgWithDefault(const option::Option *options, optionIndex index, int defaultVal) {
    if (options[index]) {
        return atoi(options[index].arg);
    } else {
        return defaultVal;
    }
}

double getRatio(const option::Option *options);

#endif /* _CMD_LINE_UTILS_H_ */
