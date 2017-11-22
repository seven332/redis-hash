#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

#include "dict.h"

uint64_t stringHash(const void *key) {
    return atoi(key) % 10;
}

int stringCompare(void *privdata, const void *key1, const void *key2) {
    return strcmp(key1, key2) == 0;
}

static dictType stringDictType = { stringHash, NULL, NULL, stringCompare, NULL, NULL };

void checkDict(dict* d) {
    if (dictCheckBucketSize(d) == DICT_ERR) {
        printf("BAD BUCKET SIZE");
    }
}

int main() {
    int i;
    int count;
    const int max = 1000;

    srandom(time(NULL));

    dict* dict1 = dictCreate(&stringDictType, NULL);

    dictAdd(dict1, "01", "aaa");
    dictAdd(dict1, "02", "bbb");
    dictAdd(dict1, "12", "ccc");
    dictAdd(dict1, "22", "ddd");
    dictAdd(dict1, "32", "eee");
    dictAdd(dict1, "42", "fff");
    dictAdd(dict1, "52", "ggg");
    dictAdd(dict1, "62", "hhh");
    dictAdd(dict1, "72", "iii");
    dictAdd(dict1, "82", "jjj");
    dictAdd(dict1, "92", "kkk");

    count = 0;
    for (i = 0; i < max; i++) {
        if (strcmp("aaa", dictGetRandomKey(dict1)->v.val) == 0) {
            count++;
        }
    }
    printf("dictGetRandomKey  aaa %d/%d\n", count, max);

    count = 0;
    for (i = 0; i < max; i++) {
        if (strcmp("aaa", dictGetRandomKey2(dict1)->v.val) == 0) {
            count++;
        }
    }
    printf("dictGetRandomKey2 aaa %d/%d\n", count, max);

    return 0;
}
