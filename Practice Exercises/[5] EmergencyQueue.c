#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
    int patient_id;
    int priority_num;
    String patient_name;
    String reason;
} PatientPriorityInfo;

typedef struct {
    PatientPriorityInfo patients[32];
    int last; // Represents the index of the last element
} HEAP;

// --- INSERT FUNCTION ---
void insertPatient(HEAP *heap, PatientPriorityInfo patient) {
    if (heap->last >= 31) {
        printf("Heap is full.\n");
        return;
    }
    heap->last++;
    heap->patients[heap->last] = patient;

    int current = heap->last;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap->patients[current].priority_num > heap->patients[parent].priority_num) {
            PatientPriorityInfo temp = heap->patients[current];
            heap->patients[current] = heap->patients[parent];
            heap->patients[parent] = temp;
            current = parent;
        } else {
            break;
        }
    }
}

// --- DELETE FUNCTION ---
void deleteFirst(HEAP *heap) {
    if (heap->last < 0) {
        printf("Queue is empty.\n");
        return;
    }
    PatientPriorityInfo top = heap->patients[0];
    printf(">> SERVING: %s (Priority %d) - %s\n", 
           top.patient_name, top.priority_num, top.reason);

    heap->patients[0] = heap->patients[heap->last];
    heap->last--;

    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int largest = current;

        if (left <= heap->last && heap->patients[left].priority_num > heap->patients[largest].priority_num)
            largest = left;
        if (right <= heap->last && heap->patients[right].priority_num > heap->patients[largest].priority_num)
            largest = right;

        if (largest != current) {
            PatientPriorityInfo temp = heap->patients[current];
            heap->patients[current] = heap->patients[largest];
            heap->patients[largest] = temp;
            current = largest;
        } else {
            break;
        }
    }
}

// --- MAIN (FOR TESTING) ---
int main() {
    HEAP myHeap;
    myHeap.last = -1; // Initialize heap as empty

    // Create Dummy Patients
    PatientPriorityInfo p1 = {101, 10, "John Doe", "Flu"};
    PatientPriorityInfo p2 = {102, 50, "Jane Smith", "Heart Attack"}; // High Priority
    PatientPriorityInfo p3 = {103, 20, "Bob Jones", "Broken Arm"};
    PatientPriorityInfo p4 = {104, 40, "Alice Guo", "Severe Burn"};

    printf("--- Inserting Patients ---\n");
    insertPatient(&myHeap, p1);
    insertPatient(&myHeap, p2);
    insertPatient(&myHeap, p3);
    insertPatient(&myHeap, p4);

    // Jane Smith (50) should come out first, followed by Alice (40)
    printf("\n--- Processing Queue ---\n");
    deleteFirst(&myHeap);
    deleteFirst(&myHeap);
    deleteFirst(&myHeap);
    deleteFirst(&myHeap);

    return 0;
}