// C program reads records from a file and inserts them into a hashtable using linear probing to handle collisions

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct record{
    char name[20];
    int id, flag;
} ht[10];
int hash(int key){
    int value, slots = 10;
    value = key % slots;
    return value;
}
int main(){
    FILE *in;
    int i, j, k, n, id, location;
    char name[20];
    printf("Enter the no. of records: ");
    scanf("%d", &n);
    in = fopen("f.txt", "r");
    if (n <= 10){
        for (k = 0; k < 10; k++)
            ht[k].flag = 0;
        for (i = 0; i < n; i++){
            fscanf(in, "%d %s", &id, name);
            location = hash(id);
            if (ht[location].flag == 0){
                printf("The address of %d record is %d\n", i + 1, location);
                strcpy(ht[location].name, name);
                ht[location].id = id;
                ht[location].flag = 1;
            }
            else{
                printf("Collision detected\n");
                for (j = location + 1; (j % 10) < 10; j++){
                    if (!ht[j % 10].flag){
                        printf("The address of %d record is %d\n", i + 1, j % 10);
                        strcpy(ht[j % 10].name, name);
                        ht[j % 10].id = id;
                        ht[j % 10].flag = 1;
                        break;
                    }
                }
            }
        }
    }
    fclose(in);
    printf("The hashtable contents are\n");
    for (k = 0; k < 10; k++){
        if (ht[k].flag == 0)
            printf("##\n");
        else
            printf("%d\t%s\n", ht[k].id, ht[k].name);
    }

    return 0;
}

// Commands to run the program:
  mkdir Hashing
  cd Hashing
  gedit Hash.c
  gedit filename.txt
  gcc Hash.c -o Hash
  ./Hash
  
// Structure Definition:
// The program defines a structure record to hold information about each record, including name, ID, and
// a flag to indicate whether the slot is occupied.
//
// hash Function:
// This function calculates the hash value for a given key (ID).
// It takes the key as input and calculates the hash value using the modulo operation.
// The hash value determines the location in the hashtable where the record will be stored.
//
// main Function:
// The main function is the entry point of the program.
// It prompts the user to enter the number of records.
// It initializes the hashtable and opens a file ("f.txt") for reading records.
// For each record in the file:
// It reads the ID and name from the file.
// It calculates the hash value using the hash function.
// If the slot at the calculated location is empty, it stores the record there.
// If a collision occurs (i.e., the slot is already occupied), it uses linear probing to find
// the next available slot and stores the record there.
// After processing all records, it closes the file and prints the contents of the hashtable.
// It prints "##" for empty slots and displays the ID and name for occupied slots.
//
// Output:
// The program prints the address (index) of each record in the hashtable.
// It handles collisions by printing "Collision detected" and finding the next available slot.
// Finally, it displays the contents of the hashtable, showing the records stored at each index.
// Overall, this program demonstrates the use of a hashtable with linear probing to store records read from a file.
