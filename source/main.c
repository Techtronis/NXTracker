// Include the most common headers from the C standard library
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
char handConNames[11][99] = {"Game & Watch", "Game Boy",
                            "Game Boy Color", "Game Boy Advance",
                            "Game Boy Advance SP", "Game Boy Micro",
                            "Nintendo DS", "Nintendo DS Lite",
                            "Nintendo DSi (XL)", "(New) Nintendo 3DS (XL)",
                            "(New) Nintendo 2ds"};
//      Current Consoles
char currConNames[3][99] = {"Nintendo Switch", "Nintendo Switch Lite", "Nintendo Switch OLED model"};

int consoleSelectScreen(int y)
{
    consoleInit(NULL);
    consoleUpdate(NULL);

    printf("NXTracker v0.0.1\n \n");
    printf("Choose a console \n \n");

    if (y == 0)
    {
        for(int i = 0; i <= 8; i++)
        {
            printf(homeConNames[i]);
            printf("\n \n");
        }
        consoleUpdate(NULL);
    }
    else if (y == 1)
    {
        for(int i = 0; i <= 11; i++)
        {
            printf(handConNames[i]);
            printf("\n \n");
        }
        consoleUpdate(NULL);
    }
    else if (y == 2)
    {
        for(int i = 0; i <= 3; i++)
        {
            printf(currConNames[i]);
            printf("\n \n");
        }
        consoleUpdate(NULL);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int x = 0;

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)

    PadState pad;
    padInitializeDefault(&pad);
    consoleInit(NULL);

    x = 0;
    printf("NXTracker v0.1\n \n");
    printf("Categories: \n\n [A] Home Consoles \n\n [B] Handheld Consoles [X] Current Consoles");

    // Main loop
    while (appletMainLoop())
    {
        // Scan the gamepad. This should be done once for each frame
        u64 kDown = padGetButtonsDown(&pad);
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one

        padConfigureInput(1, HidNpadStyleSet_NpadStandard);

        if (kDown & HidNpadButton_Down)
        {
            consoleSelectScreen(0);
            consoleUpdate(NULL);
        }
        else if (kDown & HidNpadButton_Right)
        {
            consoleSelectScreen(1);
            consoleUpdate(NULL);
        }
        else if (kDown & HidNpadButton_Left)
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
