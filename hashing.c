#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Hash function: h(k) = k % m
int hash(int key, int m) {
    return key % m;
}

int quadra(int table[],int m,int index)
{
    int i=1;
    while (table[index] != -1) {
        index=(index+(i*i)) % m;
        i++;
    }
    return index;
}

// Insertion with linear probing
void insert(int table[], int key, int m) {
    int index = hash(key, m);
    
    // Linear probing
   /* while (table[index] != -1) {
        //index = (index + 1) % m; // Move to next index
    }*/
    if(table[index]!=-1)
    index=quadra(table,m,index);

    table[index] = key;
}

// Display the hash table
void display(int table[], int m) {
    printf("Hash Table:\n");
    for (int i = 0; i < m; i++) {
        printf("Index %d: ", i);
        if (table[i] != -1) {
            printf("%d", table[i]);
        }
        printf("\n");
    }
}

int main() {
    int size, num_keys;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    int hash_table[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        hash_table[i] = -1; // Initialize all elements to -1 (indicating empty)
    }

    printf("Enter the number of keys to insert: ");
    scanf("%d", &num_keys);

    printf("Enter %d keys:\n", num_keys);
    for (int i = 0; i < num_keys; i++) {
        int key;
        scanf("%d", &key);
        insert(hash_table, key, size);
    }

    // Display the hash table
    display(hash_table, size);

    return 0;
}