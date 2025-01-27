#include "buzzer_functions.h"


void play_buzzer(int* melody , int noteDuration , int melody_len){
  for (int i = 0; i < melody_len ; i++) {
    tone(BUZZER_PIN, melody[i],1000/noteDuration);
    delay(1000/noteDuration);
  }
    noTone(BUZZER_PIN);
}