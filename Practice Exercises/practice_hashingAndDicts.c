//Dictionary (simulate a dictionary with a struct)
#include <stdio.h>
#include <string.h>

#define SIZE 5

// A dictionary entry
typedef struct {
    char key[20];
    char value[50];
} DictEntry;

int main() {
    DictEntry dict[SIZE];  // array of dictionary entries
    int count = 0;

    // Insert entries
    strcpy(dict[count].key, "apple");
    strcpy(dict[count].value, "a fruit");
    count++;

    strcpy(dict[count].key, "dog");
    strcpy(dict[count].value, "an animal");
    count++;

    // Search
    char word[20] = "dog";
    for (int i = 0; i < count; i++) {
        if (strcmp(dict[i].key, word) == 0) {
            printf("%s → %s\n", dict[i].key, dict[i].value);
        }
    }

    return 0;
}

//Hashing (Fast Dictionary Implementation)
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

// Dictionary entry (chaining not included here)
typedef struct {
    char key[20];
    char value[50];
} DictEntry;

DictEntry hashTable[TABLE_SIZE];

// Simple hash function (sum of chars % table size)
int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Insert into hash table
void insert(char *key, char *value) {
    int index = hash(key);
    strcpy(hashTable[index].key, key);
    strcpy(hashTable[index].value, value);
}

// Search in hash table
char* search(char *key) {
    int index = hash(key);
    if (strcmp(hashTable[index].key, key) == 0) {
        return hashTable[index].value;
    }
    return NULL;
}

int main() {
    insert("dog", "an animal");
    insert("apple", "a fruit");

    char *result = search("dog");
    if (result) {
        printf("dog → %s\n", result);
    } else {
        printf("dog not found!\n");
    }

    return 0;
}