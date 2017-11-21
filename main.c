#include <stdio.h>
#include <memory.h>

#include "dict.h"
#include "sds.h"

uint64_t dictSdsHash(const void *key) {
    return dictGenHashFunction((unsigned char*)key, sdslen((char*)key));
}

int dictSdsKeyCompare(void *privdata, const void *key1,
                      const void *key2)
{
    int l1,l2;
    DICT_NOTUSED(privdata);

    l1 = sdslen((sds)key1);
    l2 = sdslen((sds)key2);
    if (l1 != l2) return 0;
    return memcmp(key1, key2, l1) == 0;
}

void dictSdsDestructor(void *privdata, void *val)
{
    DICT_NOTUSED(privdata);
    sdsfree(val);
}

int main() {

    dictType clusterNodesDictType = {
            dictSdsHash,                /* hash function */
            NULL,                       /* key dup */
            NULL,                       /* val dup */
            dictSdsKeyCompare,          /* key compare */
            dictSdsDestructor,          /* key destructor */
            NULL                        /* val destructor */
    };

    dict* dict1 = dictCreate(&clusterNodesDictType, NULL);

    dictAdd(dict1, "1", "aaa");
    dictAdd(dict1, "2", "bbb");
    dictAdd(dict1, "3", "ccc");

    printf("%s\n", dictFind(dict1, "1")->v);

    return 0;
}
