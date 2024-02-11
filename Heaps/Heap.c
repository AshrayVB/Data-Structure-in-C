// C program implements basic operations on a max heap, including insertion and deletion.

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int ar[], int size, int i) {
    int largest = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    if (L < size && ar[L] > ar[largest]) {
        largest = L;
    }

    if (R < size && ar[R] > ar[largest]) {
        largest = R;
    }

    if (largest != i) {
        swap(&ar[i], &ar[largest]);
        heapify(ar, size, largest);
    }
}

void insert(int ar[], int *size, int nn) {
    if (*size == 0) {
        ar[0] = nn;
        *size = *size + 1;
    } else {
        ar[*size] = nn;
        *size += 1;
        for (int i = (*size / 2) - 1; i >= 0; i--) {
            heapify(ar, *size, i);
        }
    }
}

void delete(int ar[], int *size, int num) {
    int i, flag = 0;
    for (i = 0; i < *size; i++) {
        if (num == ar[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        swap(&ar[i], &ar[*size - 1]);
        *size -= 1;

        for (i = (*size / 2) - 1; i >= 0; i--) {
            heapify(ar, *size, i);
        }
    } else {
        printf("Element not found\n");
    }
}


void main() {
    int n, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int ar[n];
    int size = 0;

    printf("Enter elements: ");
    for (j = 0; j < n; j++) {
        scanf("%d", &ar[j]);
        size++;
        heapify(ar, size, j);
    }
    printf("Heap: ");
    display(ar, size);
    int ins,del;
    printf("Enter element to insert: ");
    scanf("%d", &ins);
    insert(ar, &size, ins);
    display(ar, size);
    printf("Enter element to delete: ");
    scanf("%d", &del);
    delete(ar, &size, del);
    display(ar, size);
}

// The loop correctly checks for the presence of the element in the array.
// If the element is found, flag is set to 1, and the loop breaks.
// After the loop, if flag is 1, it means the element was found, and deletion proceeds as before.
// If flag remains 0 after the loop, it means the element was not found, and a corresponding message is printed.
