// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <switch.h>

char conNames[9][99] = {"Nintendo Switch \n", "Wii U \n",
                        "Wii \n", "Gamecube \n", 
                        "Nintendo 64 \n", "Virtual Boy \n", 
                        "SNES \n", "NES \n"};

int consoleSelectScreen(int y)
{
    while(appletMainLoop)
    {
        consoleInit(NULL);
        consoleUpdate(NULL);
        printf("NXTracker v0.0.1\n \n");
        printf("console select");

        if(y == 0)
        {
            printf("home consoles");
            consoleUpdate(NULL);
        }
        else if (y == 1)
        {
            printf("handheld consoles");
            consoleUpdate(NULL);
        }
        else if (y == 2)
        {
            printf("current consoles");
            consoleUpdate(NULL);
        }
    }

    return 0;
}

int categorySelectScreen()
{
    while(appletMainLoop)
    {
        consoleInit(NULL);
        printf("NXTracker v0.0.1\n \n");
        printf("Categories: \n\n [A] Home Consoles \n\n [B] Handheld Consoles [X] Current Consoles");

        padConfigureInput(1, HidNpadStyleSet_NpadStandard);
        PadState pad;
        padInitializeDefault(&pad);
        u64 kDown = padGetButtonsDown(&pad);

        if(kDown & HidNpadButton_A)
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
    
    }
    return 0;
}

int main(int argc, char* argv[])
{

    int x = 0;
    

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

        categorySelectScreen();

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);

        /*if (kDown & HidNpadButton_Right)
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
        }*/
        
        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
