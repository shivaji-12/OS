#include <stdio.h>

#define TOTAL_BLOCKS 100 // Total number of blocks in the disk

void allocateFile(int startBlock, int fileSize, int disk[]) {
    int endBlock = startBlock + fileSize - 1;

    // Check if the blocks are available for allocation
    for (int i = startBlock; i <= endBlock; i++) {
        if (disk[i] != 0) {
            printf("Block %d is already allocated.\n", i);
            return;
        }
    }

    // Allocate the blocks for the file
    for (int i = startBlock; i <= endBlock; i++) {
        disk[i] = 1;
    }

    printf("File allocated from block %d to %d.\n", startBlock, endBlock);
}

void displayDiskStatus(int disk[]) {
    printf("Disk Status:\n");
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        printf("Block %d: %s\n", i, (disk[i] == 0) ? "Free" : "Occupied");
    }
}

int main() {
    int disk[TOTAL_BLOCKS] = {0}; // Initialize disk blocks to 0 (free)

    // Allocate files using continuous file allocation method
    allocateFile(10, 5, disk);
    allocateFile(25, 8, disk);
    allocateFile(40, 3, disk);
    allocateFile(70, 6, disk);
    allocateFile(90, 12, disk);

    // Display the status of disk blocks
    displayDiskStatus(disk);

    return 0;
}

