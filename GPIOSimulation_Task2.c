#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>   
#include <conio.h>     

#define STABLE_COUNT 5   /* after 5 consecutive same values we are sure that the button 
was really pressed or not (1 means pressed, 0 means not pressed) */ 



int generatedSignals() {
    int val = rand() % 2;
    printf("%d ", val);   // to see the real bouncing alghorithm
    fflush(stdout);
    return val;
}

int checkButton() {
    int stableSignals, count = 0;
    stableSignals = generatedSignals();

    while (count < STABLE_COUNT) {
        int current = generatedSignals();
        if (current == stableSignals) {
            count++;
        }
        else {
            count = 0;          
            stableSignals = current;
        }
        Sleep(10);  // 10ms delay 
    }
    printf(" -> Stable: %d\n", stableSignals); // show final decision if 1 it toggles but 0 means button was not pressed really and nothing changes
    return stableSignals;
}

int main() {
    srand((unsigned)time(NULL));
    int ledState = 0;

    printf("Press any key to simulate button press, 'q' to quit.\n");

    while (1) {
        int input = _getch();   // read key without Enter
        if (input == 'q' || input == 'Q')
            break;

        int button = checkButton();

        if (button == 1) {
            ledState = !ledState;
            if (ledState)
                printf("*\n"); // means the LED is ON 
            else
                printf("\n"); // means the LED is OFF
        }
    }
    return 0;
}
