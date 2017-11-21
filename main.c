#include <stdio.h>
#include <memory.h>

#include "dict.h"

uint64_t stringHash(const void *key) {
    unsigned char *str = key;
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int stringCompare(void *privdata, const void *key1, const void *key2) {
    return strcmp(key1, key2) == 0;
}

int main() {

    dictType stringDictType = {
            stringHash,                /* hash function */
            NULL,                       /* key dup */
            NULL,                       /* val dup */
            stringCompare,          /* key compare */
            NULL,                       /* key destructor */
            NULL                        /* val destructor */
    };

    dict* dict1 = dictCreate(&stringDictType, NULL);

    dictAdd(dict1, "1", "aaa");
    dictAdd(dict1, "2", "bbb");
    dictAdd(dict1, "3", "ccc");

    printf("%s\n", dictFind(dict1, "3")->v);

    return 0;
}
