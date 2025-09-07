#include <Wire.h>
#include <U8g2lib.h>
#include "Display.h"

// OLED
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// Menu
const char* menuNames[] = {"HUD","Time & Date","Notifications","Stopwatch","Tasks","Weather","Temperature"};
const int numItems = sizeof(menuNames)/sizeof(menuNames[0]);
int currentIndex = 0;

// Buttons
const int btnUp = 2;
const int btnDown = 3;
const int btnSelect = 4;

// Previous states
int prevUp = HIGH;
int prevDown = HIGH;
int prevSelect = HIGH;

void setup() {
    Wire.setClock(400000);
    u8g2.begin();

    pinMode(btnUp, INPUT_PULLUP);
    pinMode(btnDown, INPUT_PULLUP);
    pinMode(btnSelect, INPUT_PULLUP);

   // popupText("WELCOME");
    //showText("CONNECTED");

    // Draw first menu
    u8g2.firstPage();
    do { 
        drawMenuItem(menuIcons[currentIndex], menuNames[currentIndex], 12);
    } while (u8g2.nextPage());
}

void loop() {
    int upState = digitalRead(btnUp);
    int downState = digitalRead(btnDown);
    int selectState = digitalRead(btnSelect);

    // UP button pressed (on release)
    if (prevUp == LOW && upState == HIGH) {
        int newIndex = currentIndex - 1;
        if (newIndex < 0) newIndex = numItems - 1;
        slideMenuVertical(menuNames, currentIndex, newIndex);
        currentIndex = newIndex;
    }

    // DOWN button pressed (on release)
    if (prevDown == LOW && downState == HIGH) {
        int newIndex = currentIndex + 1;
        if (newIndex >= numItems) newIndex = 0;
        slideMenuVertical(menuNames, currentIndex, newIndex);
        currentIndex = newIndex;
    }

    // SELECT button pressed (on release)
    if (prevSelect == LOW && selectState == HIGH) {
        handleMenuSelection(currentIndex, btnSelect, btnUp, btnDown);
    }

    // Save previous states
    prevUp = upState;
    prevDown = downState;
    prevSelect = selectState;

    delay(20); // Small debounce delay
}
