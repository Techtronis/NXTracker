// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <switch.h>

char conNames[9][99] = {"Nintendo Switch \n", "Wii U \n",
                        "Wii \n", "Gamecube \n",
                        "Nintendo 64 \n", "Virtual Boy \n",
                        "SNES \n", "NES \n"};

int consoleSelectScreen(int y)
{
    consoleInit(NULL);
    consoleUpdate(NULL);

    printf("NXTracker v0.0.1\n \n");
    printf("Select a category: \n \n");

    if (y == 0)
    {
        printf("Home Consoles");
        consoleUpdate(NULL);
    }
    else if (y == 1)
    {
        printf("Handheld Consoles");
        consoleUpdate(NULL);
    }
    else if (y == 2)
    {
        printf("Current Consoles");
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
    printf("NXTracker v0.0.1\n \n");
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
