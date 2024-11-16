#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

void drawMainMenu()
{
    DrawText("OPCIONES FUNCIONALES 3 Y 4", 10, 10, 30, DARKGRAY);
    //DrawText("Welcome to Hunkei Impact", 10, 10, 30, DARKGRAY);
    DrawText("Select an option:", 10, 70, 30, DARKGRAY);
    DrawText("1. Start new game", 10, 110, 30, DARKGRAY);
    DrawText("2. Load game", 10, 150, 30, DARKGRAY);
    DrawText("3. Credits", 10, 190, 30, DARKGRAY);
    DrawText("Press ESC to exit", 10, 330, 30, DARKGRAY);
}

void selectOption()
{

    int option = 0;

    option = 3;

    switch (option)
    {

    case 1:
        
        break;

    case 2:
        break;

    case 3:

            
            {
                
            DrawText("Credits:", 10, 10, 30, DARKGRAY);
            
            DrawText("Developed by: Liiipicotres", 10, 50, 30, DARKGRAY);
           
            DrawText("Art by: SuperNigger69_", 10, 90, 30, DARKGRAY);

            DrawText("Music by: NiggaBeats", 10, 130, 30, DARKGRAY);

            DrawText("Special thanks to: BigNigga", 10, 170, 30, DARKGRAY);
           
            DrawText("Return to main menu (press b)", 10, 210, 30, DARKGRAY);
            }
        break;

    case 4:
        break;

    default:
        break;
    }
}
