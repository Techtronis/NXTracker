// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>

int main(int argc, char* argv[])
{

    int x = 0;
    char conNames[9][99] = {"Nintendo Switch \n Release Date: 03.03.2017", "Wii U \n Release Date: 2012", "Wii \n", "Gamecube \n", "Nintendo 64 \n", "Virtual Boy \n", "SNES \n", "NES \n"};

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);
    consoleInit(NULL);
    printf("NXTracker v0.0.1\n \n");
    x = 0;
    printf(conNames[x]);

    // Main loop
    while (appletMainLoop())
    {
        // Scan the gamepad. This should be done once for each frame
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Right)
        {
            consoleInit(NULL);
            if(x != 8){
                printf("NXTracker v0.0.1\n \n ");
                x = x + 1;
                printf(conNames[x]);
            } else {
                printf("NXTracker v0.0.1\n \n ");
                x = 0;
                printf(conNames[x]);
            }
        }
        else if (kDown & HidNpadButton_Left)
        { 
            consoleInit(NULL);
            if(x != -1){
                printf("NXTracker v0.0.1\n \n ");
                x = x - 1;
                printf(conNames[x]);
            } else {
                printf("NXTracker v0.0.1\n \n ");
                x = 7;
                printf(conNames[x]);
            }
        }
        
        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
