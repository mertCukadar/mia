#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "screen_functions.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void init_screen(){  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}


void clear_screen(){
  display.clearDisplay();
  display.display();

}


void write_text(char *text , int textSize , int x , int y){
  clear_screen();
  display.setTextColor(WHITE);
  display.setCursor(x,y);
  display.setTextSize(textSize);
  display.println(text);
  display.display();
}


