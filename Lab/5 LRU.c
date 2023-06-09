#include <stdio.h>

#define FRAME_SIZE 3 // Number of frames in the page table

int main() {
    int page_table[FRAME_SIZE] = {-1, -1, -1}; // Initialize page table frames to -1 (empty)
    int pages[] = {0, 1, 2, 3, 2, 4, 5, 3, 4, 1}; // Reference string
    int page_faults = 0; // Counter for page faults
    int page_age[FRAME_SIZE] = {0}; // Array to track the age of each page in the page table

    for (int i = 0; i < sizeof(pages) / sizeof(pages[0]); i++) {
        int page = pages[i];
        int page_found = 0;
        int oldest_page_index = 0;

        for (int j = 0; j < FRAME_SIZE; j++) {
            if (page_table[j] == page) {
                page_found = 1;
                page_age[j] = i + 1; // Update the age of the page to the current reference index
                break;
            }
            if (page_age[j] < page_age[oldest_page_index]) {
                oldest_page_index = j; // Find the index of the oldest page in the page table
            }
        }

        if (!page_found) {
            page_table[oldest_page_index] = page; // Replace the oldest page with the current page
            page_age[oldest_page_index] = i + 1; // Update the age of the newly inserted page
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

