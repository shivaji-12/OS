#include <stdio.h>

#define FRAME_SIZE 3 // Number of frames in the page table

int main() {
    int page_table[FRAME_SIZE] = {-1, -1, -1}; // Initialize page table frames to -1 (empty)
    int pages[] = {0, 1, 2, 3, 2, 4, 5, 3, 4, 1}; // Reference string
    int page_faults = 0; // Counter for page faults
    int next_frame_index = 0; // Index to track the next available frame in the page table

    for (int i = 0; i < sizeof(pages) / sizeof(pages[0]); i++) {
        int page = pages[i];
        int page_found = 0;

        // Check if the page is already in the page table
        for (int j = 0; j < FRAME_SIZE; j++) {
            if (page_table[j] == page) {
                page_found = 1;
                break;
            }
        }

        // If page is not found in the page table, it is a page fault
        if (!page_found) {
            // Replace the oldest page in the page table with the current page
            page_table[next_frame_index] = page;
            next_frame_index = (next_frame_index + 1) % FRAME_SIZE; // Increment frame index in a circular manner
            page_faults++;
        }

        // Print the current state of the page table
        printf("Page Table: ");
        for (int j = 0; j < FRAME_SIZE; j++) {
            printf("%2d ", page_table[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}

