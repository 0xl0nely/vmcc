#ifndef HASHTABLE_H
#define HASHTABLE_H
/*
    open addressing hash table with the help of the robin hood algorithm to remove the open addressing
    worst case scenario
*/
class HashTable {
private:
    int capacity;
public:
    HashTable(int);
    ~HashTable();
};

#endif
