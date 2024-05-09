#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    char* key;
    char* value;
    struct Node* next;
};

struct Hash {
    int size;
    struct Node* head;
};

struct HashTable {
    int size;
    struct Hash** hashes;
};

struct HashTable* CreateHashTable(int size) {
    struct HashTable* table = (struct HashTable*)malloc(sizeof(struct HashTable*));

    table->size = size;
    table->hashes = (struct Hash**)malloc(sizeof(struct Hash) / size);

    for (int i = 0; i < size; i++) {
        table->hashes[i] = (struct Hash*)malloc(sizeof(struct Hash));
        table->hashes[i]->head = (struct Node*)malloc(sizeof(struct Node));
        
        table->hashes[i]->size = 0;
        table->hashes[i]->head->key = "";
        table->hashes[i]->head->value = "";
        table->hashes[i]->head->next = NULL;
    }

    return table;
}

int hash(struct HashTable* table, char* key) {
    int total = 0;

    for (int i = 0; i < strlen(key); i++) {
        total += key[i];
    }

    return total % table->size;
}

void add(struct HashTable* table, char* key, char* value) {
    int hashedKey = hash(table, key);
    
    if (table->hashes[hashedKey]->size == 0) {
        table->hashes[hashedKey]->head->key = key;
        table->hashes[hashedKey]->head->value = value;
        table->hashes[hashedKey]->head->next = NULL; 

       table->hashes[hashedKey]->size = 1;
    } else {
        bool finded = false;
        struct Node* cur = table->hashes[hashedKey]->head;
        struct Node* prev = NULL;

        while(cur) {
            if (cur->key == key) {
                finded = true;
                cur->value = value;
            }

            prev = cur;
            cur = cur->next;
        }

        if (!finded) {
            prev->next = (struct Node*)malloc(sizeof(struct Node));
            prev->next->key = key;
            prev->next->value = value;
            prev->next->next = NULL;
        }

        table->hashes[hashedKey]->size += 1;
    }
}

char* get(struct HashTable* table, char* key) {
    int hashedKey = hash(table, key);

    if (table->hashes[hashedKey]->size == 0) return "null";

    if (table->hashes[hashedKey]->size == 1) {
        if (table->hashes[hashedKey]->head->key == key) {
            return table->hashes[hashedKey]->head->value;
        } else {
            return "null";
        }
    } else {
        struct Node* cur = table->hashes[hashedKey]->head;
        struct Node* prev = NULL;

        while(cur) {
            if (cur->key == key) {
                return cur->value;
            }

            prev = cur;
            cur = cur->next;
        }

        return "null";
    }
}

bool exists(struct HashTable* table, char* key) {
    int hashedKey = hash(table, key);

    if (!table->hashes[hashedKey]) return false;

    struct Node* cur = table->hashes[hashedKey]->head;
    struct Node* prev = NULL;

    while (cur) {
        if (cur->key == key) {
            return true;
        }

        prev = cur;
        cur = cur->next;
    }

    return false;
}

void removeKey(struct HashTable* table, char* key) {
    int hashedKey = hash(table, key);

    if (table->hashes[hashedKey]->size == 0 || !table->hashes[hashedKey]) return;

    struct Node* cur = table->hashes[hashedKey]->head;
    struct Node* prev = NULL;

    while(cur) {
        if (cur->key == key) {
            if (table->hashes[hashedKey]->size == 1) {
                table->hashes[hashedKey]->head = (struct Node*)malloc(sizeof(struct Node));
                table->hashes[hashedKey]->head->key = "";
                table->hashes[hashedKey]->head->value = "";
                table->hashes[hashedKey]->head->next = NULL;
            } else {
                prev->next = cur->next;
                free(cur);
                cur = NULL;
            }

            table->hashes[hashedKey]->size -= 1;
        }

        prev = cur;
        cur = cur->next;
    }
}

void main() {
    struct HashTable* hashTable = CreateHashTable(4);
}