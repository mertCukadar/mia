#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// screen_functions.h

void clear_screen();
void write_text(char *text , int textSize , int x , int y);
void init_screen();
