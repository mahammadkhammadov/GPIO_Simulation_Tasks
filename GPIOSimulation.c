#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    char ch;
    int ledState = 0;  // 0 = OFF, 1 = ON

    printf("Press any buuton to toggle LED, 'q' to quit.\n");

    while (1) {
            
        ch = _getch();

        if (ch == 'q' || ch == 'Q') {
            break;          
        }
        else {
            ledState = !ledState;
            if (ledState)
                printf("*\n"); // means the LED is ON 
            else
                printf("\n");  // means the LED is OFF
        }
        
    }

    return 0;
}
