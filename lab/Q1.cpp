#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
using namespace std;

#define TABLE_SIZE 10
#define BUFFER_SIZE 1024

typedef struct FileNode {
    char* filename;
    struct FileNode* next;
} FileNode;

typedef struct WordNode {
    char* word;
    FileNode* fileList;
    struct WordNode* next;
} WordNode;

typedef struct {
    WordNode** table;
} HashTable;

unsigned int hashing(const char* str) { 
    unsigned int hash_value = 5381; 
    int c;
    while ((c = *str++)) {
        hash_value = ((hash_value << 5) + hash_value) + c; 
    }
    return hash_value % TABLE_SIZE;
}


char* strCopy(const char* s) {
    if (!s) return nullptr;

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    len++; 

    char* copy = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        copy[i] = s[i];
    }

    return copy;
}


HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (WordNode**)malloc(TABLE_SIZE * sizeof(WordNode*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = nullptr;
    }
    return ht;
}


void freeHashTable(HashTable* ht) {
    if (!ht) return;
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordNode* word_current = ht->table[i];
        while (word_current) {
            WordNode* word_temp = word_current;
            word_current = word_current->next;

            FileNode* file_current = word_temp->fileList;
            while (file_current) {
                FileNode* file_temp = file_current;
                file_current = file_current->next;
                free(file_temp->filename); 
                free(file_temp);           
            }

            free(word_temp->word); 
            free(word_temp);       
        }
    }
    free(ht->table); 
    free(ht);        
}


void insert(HashTable* ht, const char* word, const char* filename) {
    unsigned int index = hashing(word);
    WordNode* current = ht->table[index];

    while (current) {
        if (strcmp(current->word, word) == 0) {
            FileNode* file_current = current->fileList;
            while (file_current) {
                if (strcmp(file_current->filename, filename) == 0) {
                    return; 
                }
                file_current = file_current->next;
            }
            FileNode* new_file = (FileNode*)malloc(sizeof(FileNode));;
            new_file->filename = strCopy(filename);
            new_file->next = current->fileList;
            current->fileList = new_file;
            return;
        }
        current = current->next;
    }

    WordNode* new_word = (WordNode*)malloc(sizeof(WordNode));
    new_word->word = strCopy(word);
    new_word->fileList = nullptr;
    new_word->next = ht->table[index];

    FileNode* new_file = (FileNode*)malloc(sizeof(FileNode));
    new_file->filename = strCopy(filename);
    new_file->next = nullptr;
    new_word->fileList = new_file;

    ht->table[index] = new_word;
}


void search(HashTable* ht, const char* word) {
    unsigned int index = hashing(word);
    WordNode* current = ht->table[index];

    while (current) {
        if (strcmp(current->word, word) == 0) {
            cout << word << " : " ;
            FileNode* file_current = current->fileList;
            while (file_current) {
                cout << file_current->filename << ", " ;
                file_current = file_current->next;
            }
            cout << endl;
            return;
        }
        current = current->next;
    }
    cout << word << " --> not found " << endl;
}

void readFileAndIndex(const char* filename, HashTable* index) { 
    FILE* file = fopen(filename, "r");
    if (!file) {
        cout << "Error opening file: " << filename ;
        return;
    }
    char buffer[BUFFER_SIZE];
    const char* delimiters = " ,.!?;:\n\r";
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char* token = strtok(buffer, delimiters);
        while (token != NULL) {
            insert(index, token, filename);
            token = strtok(NULL, delimiters);
        }
    }
    fclose(file);
}

int main() {
    HashTable* index = createHashTable();

    readFileAndIndex("file1.txt", index);
    readFileAndIndex("file2.txt", index);

    search(index, "Welcome");
    search(index, "data");

    freeHashTable(index);

    return 0;
}