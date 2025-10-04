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
