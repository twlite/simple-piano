#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include "frequency.h"

int makeSound(int keycode, int dur) {
    float freq = getFrequency(keycode);
    if (freq < 1) return 0;
    
    return Beep(freq, dur);
}
 
void main() {
    int keycode, dur = 500;
    
    resetLabel:
    printf("\nEnter keypress duration in ms: ");
    scanf("%d", &dur);

    if (dur < 1) dur = 500;

    printf("\nApp started! Press ctrl+c to exit & ctrl+r to restart!\n\n");

    printf(" ___________________________________________________________________________ \n");
    printf("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | |  |\n");
    printf("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | |  |\n");
    printf("|  | | | |  |  | | | | | |  |  | | | |  |  | | | | | |  |  | | | |  |  | |  |\n");
    printf("|  |S| |D|  |  |G| |H| |J|  |  |2| |3|  |  |5| |6| |7|  |  |9| |0|  |  |=|  |\n");
    printf("|  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |  |_|  |\n");
    printf("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |\n");
    printf("| Z | X | C | V | B | N | M | Q | W | E | R | T | Y | U | I | O | P | [ | ] |\n");
    printf("|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|\n\n");

    while(1) {


        // close the program
        if (keycode == 3) break;

        // restart
        else if (keycode == 18) {
            keycode = 0;
            system("cls");
            goto resetLabel;
        }

        keycode = getch();

        // update some keys
        // white
        if (keycode == 44) keycode = 113;
        else if (keycode == 46) keycode = 119;
        else if (keycode == 47) keycode = 101;

        // black
        else if (keycode == 108) keycode = 50;
        else if (keycode == 59) keycode = 51;
        makeSound(keycode, dur);
    }
}