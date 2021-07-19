#include <bits/stdc++.h>
#define TABLE_SIZE 512

struct entry {
    bool in_use;
    char* value;
};
typedef struct entry entry_t, *entry_p;
class HashTable {
    entry_t entries[TABLE_SIZE];
public:
    HashTable() {
        int i;
        for (i = 0; i < TABLE_SIZE; i++) {
            entries[i].in_use = false;
            entries[i].value = 0;
        }
    }
    // prone to collisions
    unsigned int compute_string(const char* in) {
        unsigned int n = 0, i;
        for (i = 0; in[i] != 0; i++) {
            n+=in[i];
        }
        return n;
    }
    entry_t* search(const char* in) {
        unsigned int hash = compute_string(in), offset = hash % TABLE_TABLE;

    }


}

int main(int argc, char**argv) {}
