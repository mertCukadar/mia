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


void draw_screen(char * array){
  for (int i=0; i < SCREEN_HEIGHT; i++){
    for (int j=0; j < SCREEN_WIDTH; j++){
      if(array[i*SCREEN_WIDTH+j] == '1')
        display.drawPixel(j, i, WHITE);
      else
        display.drawPixel(j, i, BLACK);
    }
  }
  display.display();

}


void draw_screen_bitmap(unsigned char * array){
  clear_screen();
  display.drawBitmap(0, 0, array, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
  display.display();
  

}




// void decodeBase64AndDisplay(String base64Data) {
//     char decoded[256]; // Çözülen veriyi saklamak için dizi (boyutu ihtiyaçlarınıza göre ayarlayabilirsiniz)

//     // Base64 verisini çöz
//     b64_decode(decoded, (char *)base64Data.c_str(), base64Data.length());

//     // Çözülmüş veriyi seri monitörde yazdır
//     Serial.println("Decoded Base64 data:");
//     for (int i = 0; i < strlen(decoded); i++) {
//         Serial.print(decoded[i], HEX); // HEX formatında yazdır
//         Serial.print(" ");
//     }
//     Serial.println();

//     // OLED ekrana bitmap çizdir
//     display.clearDisplay();
//     display.drawBitmap(0, 0, (uint8_t *)decoded, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
//     display.display();
// }


