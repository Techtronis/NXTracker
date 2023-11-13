/*
Made by: Alexis Jost
Started on: November 3rd 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <switch.h>

//      Home Consoles
char homeConNames[8][99] = {"Wii U \n",
                            "Wii \n", "Gamecube \n",
                            "Nintendo 64 \n", "Virtual Boy \n",
                            "SNES \n", "NES \n"};
//      Handheld Devices
char handConNames[11][99] = {"Game & Watch \n", "Game Boy \n",
                             "Game Boy Color \n", "Game Boy Advance \n",
                             "Game Boy Advance SP \n", "Game Boy Micro \n",
                             "Nintendo DS \n", "Nintendo DS Lite \n",
                             "Nintendo DSi (XL) \n", "(New) Nintendo 3DS (XL) \n",
                             "(New) Nintendo 2ds \n"};
//      Current Consoles
char currConNames[3][99] = {"Nintendo Switch \n", "Nintendo Switch Lite \n", "Nintendo Switch OLED model \n"};

int consoleSelectScreen(int y)
{
    consoleInit(NULL);
    consoleUpdate(NULL);

    printf("NXTracker v0.0.1\n \n");
    printf("Choose a console \n \n");

    switch(y)
    {
        case 0:
            for (int i = 0; i <= 8; i++)
            {
                printf(homeConNames[i]);
            }
            consoleUpdate(NULL);
            break;
        case 1:
            for (int i = 0; i <= 11; i++)
            {
                printf(handConNames[i]);
            }
            consoleUpdate(NULL);
            break;
        case 2:
            for (int i = 0; i <= 3; i++)
            {
                printf(currConNames[i]);
            }
            consoleUpdate(NULL);
            break;
        default:
            printf("NXTracker v0.1\n \n");
            printf("Categories: \n\n [A] Home Consoles \n\n [B] Handheld Consoles [X] Current Consoles");
            break;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);
    consoleInit(NULL);


    printf("NXTracker v0.1\n \n");

    printf("Categories: \n\n [A] Home Consoles \n\n [B] Handheld Consoles [X] Current Consoles \n \n \n");
    
    // Main loop
    while (appletMainLoop())
    {
        // Scan the gamepad. This should be done once for each frame
        u64 kDown = padGetButtonsDown(&pad);
        padUpdate(&pad);
        padConfigureInput(1, HidNpadStyleSet_NpadStandard);

        
        if (kDown & HidNpadButton_A)
        {  
            consoleSelectScreen(0);
            consoleUpdate(NULL);
        }
        else if (kDown & HidNpadButton_B)
        {
            consoleSelectScreen(1);
            consoleUpdate(NULL);
        }
        else if (kDown & HidNpadButton_X)
        {
            consoleSelectScreen(2);
            consoleUpdate(NULL);
        }

        consoleUpdate(NULL);
    }
    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
