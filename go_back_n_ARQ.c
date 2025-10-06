#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int totalFrames, windowSize;
    int base = 0, nextSeq = 0;
    
    srand(time(0));  // seed for random loss
    
    // Input total frames and window size
    printf("Enter total frames to send: ");
    scanf("%d", &totalFrames);
    printf("Enter window size: ");
    scanf("%d", &windowSize);

    printf("\n--- Go-Back-N Simulation ---\n\n");

    while (base < totalFrames) {
        // Send frames in the window
        for (int i = nextSeq; i < base + windowSize && i < totalFrames; i++) {
            printf("Sending frame %d\n", i);
            nextSeq++;
        }

        // Randomly simulate if frame at base is received or lost
        if (rand() % 2 == 1) {
            printf("ACK received for frame %d\n\n", base);
            base++;  // slide window
        } else {
            printf("Frame %d lost! Retransmitting window\n\n", base);
            nextSeq = base; // go back to base
        }
    }

    printf("All frames successfully transmitted!\n");
    return 0;
}
