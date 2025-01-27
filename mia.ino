#include "entities.h"
#include "screen_functions.h"
#include "buzzer_functions.h"
#include "api.h"

#define CHP (char *)



int melody[] = {
   NOTE_B0, NOTE_E4, NOTE_E4, NOTE_B0, NOTE_B0, NOTE_B0, NOTE_B0, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_AS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_CS4, NOTE_D4, NOTE_G5, NOTE_G5, NOTE_DS5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_CS5, NOTE_DS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_GS5, NOTE_A5, NOTE_AS7, NOTE_AS7, NOTE_AS7, NOTE_A7, NOTE_AS7, NOTE_AS5, NOTE_A5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_C8, NOTE_B6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_GS5, NOTE_A5, NOTE_A5, NOTE_C5, NOTE_GS5, NOTE_DS5, NOTE_DS5, NOTE_AS5, NOTE_AS5, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_B7, NOTE_B7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_B7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_G5, NOTE_G5, NOTE_D6, NOTE_D6, NOTE_GS5, NOTE_A5, NOTE_D7, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_G7, NOTE_G5, NOTE_G7, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_GS5, NOTE_GS5, NOTE_CS5, NOTE_G5, NOTE_G5, NOTE_CS5, NOTE_C5, NOTE_G7, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS4, NOTE_GS4, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_G5, NOTE_GS5, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_GS4, NOTE_G5, NOTE_G5, NOTE_B7, NOTE_B7, NOTE_D6, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_G7, NOTE_D6, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G7, NOTE_G7, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C6, NOTE_C6, NOTE_G5, NOTE_G5, NOTE_A7, NOTE_A7, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_A7, NOTE_C6, NOTE_G5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_CS4, NOTE_D4, NOTE_D4, NOTE_CS4, NOTE_D4, NOTE_C6, NOTE_AS7, NOTE_AS7, NOTE_AS7, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_CS6, NOTE_CS6, NOTE_A5, NOTE_A5, NOTE_B6, NOTE_AS5, NOTE_A5, NOTE_DS7, NOTE_DS7, NOTE_A5, NOTE_D7, NOTE_A7, NOTE_G5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_AS5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_F5, NOTE_AS7, NOTE_AS7, NOTE_AS7, NOTE_A7, NOTE_A7, NOTE_B6, NOTE_B6, NOTE_GS5, NOTE_B6, NOTE_B6, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_DS6, NOTE_GS5, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_AS4, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_FS6, NOTE_B6, NOTE_D5, NOTE_GS5, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_CS5, NOTE_CS5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_C7, NOTE_C7, NOTE_B6, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_D7, NOTE_G5, NOTE_G5, NOTE_AS4, NOTE_AS4, NOTE_G7, NOTE_G7, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_G5, NOTE_CS7, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C5, NOTE_G7, NOTE_G7, NOTE_G5, NOTE_G5, NOTE_GS4, NOTE_GS4, NOTE_CS5, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_A4, NOTE_B6, NOTE_B6, NOTE_GS5, NOTE_C5, NOTE_C5, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_B6, NOTE_B6, NOTE_GS4, NOTE_D7, NOTE_D7, NOTE_G5, NOTE_F6, NOTE_C6, NOTE_B6, NOTE_A7, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_F5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_C6, NOTE_C5, NOTE_F5, NOTE_F5, NOTE_C6, NOTE_C8, NOTE_C8, NOTE_AS7, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_F5, NOTE_F5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_DS7, NOTE_C6, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_B6, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_F6, NOTE_F6, NOTE_AS5, NOTE_C6, NOTE_G4, NOTE_GS4, NOTE_C5, NOTE_C6, NOTE_A7, NOTE_A7, NOTE_AS7, NOTE_AS7, NOTE_A7, NOTE_A7, NOTE_B7, NOTE_B7, NOTE_G7, NOTE_B6, NOTE_G7, NOTE_GS5, NOTE_B6, NOTE_B6, NOTE_A7, NOTE_GS7, NOTE_DS5, NOTE_GS5, NOTE_AS7, NOTE_GS5, NOTE_GS5, NOTE_DS6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_DS6, NOTE_DS6, NOTE_GS5, NOTE_GS5, NOTE_DS6, NOTE_DS6, NOTE_AS4, NOTE_A4, NOTE_D5, NOTE_DS7, NOTE_F6, NOTE_FS6, NOTE_D5, NOTE_AS5, NOTE_GS5, NOTE_F5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_GS4, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_G5, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_CS7, NOTE_C7, NOTE_C7, NOTE_G5, NOTE_G5, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_B6, NOTE_B6, NOTE_AS6, NOTE_D7, NOTE_D7, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_C7, NOTE_C7, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_B6, NOTE_C5, NOTE_AS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_FS5, NOTE_F5, NOTE_AS4, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_DS7, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F5, NOTE_F5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_A4, NOTE_A4, NOTE_F5, NOTE_D4, NOTE_FS5, NOTE_AS6, NOTE_AS4, NOTE_F5, NOTE_F5, NOTE_AS6, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_D5, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_A4, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_AS4, NOTE_AS4, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_AS4, NOTE_AS4, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_A4, NOTE_F6, NOTE_F5, NOTE_F5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_DS7, NOTE_DS7, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_E6, NOTE_DS6, NOTE_DS6, NOTE_DS5, NOTE_DS5, NOTE_DS6, NOTE_D6, NOTE_D6, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_D6, NOTE_D6, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_B6, NOTE_B6, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_C7, NOTE_B6, NOTE_DS5, NOTE_B6, NOTE_B6, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_C4, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_GS5, NOTE_C7, NOTE_DS5, NOTE_DS5, NOTE_GS5, NOTE_D5, NOTE_AS5, NOTE_DS7, NOTE_DS7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_AS7, NOTE_AS7, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C5, NOTE_C5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_DS5, NOTE_C5, NOTE_F6, NOTE_F6, NOTE_DS5, NOTE_DS5, NOTE_C6, NOTE_C6, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_C5, NOTE_DS6, NOTE_DS6, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_C6, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_B7, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_C5, NOTE_AS6, NOTE_A5, NOTE_A5, NOTE_F6, NOTE_F6, NOTE_C6, NOTE_C6, NOTE_C8, NOTE_C8, NOTE_GS4, NOTE_C7, NOTE_C7, NOTE_CS7, NOTE_CS7, NOTE_CS7, NOTE_A4, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_GS4, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_A4, NOTE_GS4, NOTE_GS4, NOTE_B6, NOTE_B6, NOTE_AS6, NOTE_B6, NOTE_C5, NOTE_C5, NOTE_B6, NOTE_F5, NOTE_F6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_F7, NOTE_F6, NOTE_E6, NOTE_F5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_C5, NOTE_DS7, NOTE_E7, NOTE_E7, NOTE_E7, NOTE_E7, NOTE_G4, NOTE_G4, NOTE_C6, NOTE_C6, NOTE_D5, NOTE_D5, NOTE_C6, NOTE_C6, NOTE_F7, NOTE_F7, NOTE_F7, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_FS6, NOTE_FS6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_A5, NOTE_C6, NOTE_C6, NOTE_GS5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_DS6, NOTE_C6, NOTE_DS6, NOTE_D5, NOTE_D5, NOTE_C6, NOTE_C6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_A5, NOTE_A5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_AS6, NOTE_B7, NOTE_B6, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_B7, NOTE_G4, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C8, NOTE_C8, NOTE_C7, NOTE_C7, NOTE_A5, NOTE_GS5, NOTE_AS6, NOTE_AS6, NOTE_D5, NOTE_A5, NOTE_A5, NOTE_GS5, NOTE_B6, NOTE_B6, NOTE_G5, NOTE_G5, NOTE_B6, NOTE_B6, NOTE_A4, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_AS6, NOTE_AS6, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_G4, NOTE_G7, NOTE_A5, NOTE_G7, NOTE_A5, NOTE_A5, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_CS7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_B6, NOTE_G4, NOTE_GS4, NOTE_D7, NOTE_G7, NOTE_D7, NOTE_D7, NOTE_CS7, NOTE_CS7, NOTE_CS7, NOTE_CS7, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_FS6, NOTE_C6, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_B7, NOTE_B7, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_B7, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_C6, NOTE_DS5, NOTE_DS5, NOTE_GS5, NOTE_DS5, NOTE_GS5, NOTE_GS5, NOTE_D7, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_GS5, NOTE_GS5, NOTE_C7, NOTE_C6, NOTE_GS5, NOTE_GS5, NOTE_C5, NOTE_G4, NOTE_B7, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_GS4, NOTE_GS4, NOTE_A4, NOTE_B6, NOTE_D5, NOTE_GS6, NOTE_B6, NOTE_B6, NOTE_A4, NOTE_B6, NOTE_B7, NOTE_B7, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_E7, NOTE_B6, NOTE_D7, NOTE_B6, NOTE_D7, NOTE_D7, NOTE_DS5, NOTE_DS7, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_A5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_A5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_DS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_GS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_C5, NOTE_G4, NOTE_D5, NOTE_B6, NOTE_B6, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_GS5, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_F6, NOTE_F6, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C6, NOTE_E5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_GS4, NOTE_B6, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_GS4, NOTE_A7, NOTE_A7, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_GS4, NOTE_GS4, NOTE_B7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS6, NOTE_GS6, NOTE_B7, NOTE_G5, NOTE_G5, NOTE_G6, NOTE_G6, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_E7, NOTE_E7, NOTE_F7, NOTE_B6, NOTE_G6, NOTE_CS7, NOTE_B6, NOTE_B6, NOTE_B7, NOTE_B7, NOTE_B6, NOTE_B6, NOTE_G4, NOTE_GS4, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS4, NOTE_G4, NOTE_G4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_B6, NOTE_GS4, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_B6, NOTE_B6, NOTE_DS7, NOTE_DS7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_C7, NOTE_DS7, NOTE_G4, NOTE_GS4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_GS4, NOTE_DS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_A5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_GS4, NOTE_GS4, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS4, NOTE_GS4, NOTE_C5, NOTE_D5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_GS5, NOTE_B4, NOTE_GS4, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_GS5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_D5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_D5, NOTE_GS5, NOTE_GS5, NOTE_C5, NOTE_C6, NOTE_C5, NOTE_C5, NOTE_C6, NOTE_C4, NOTE_G6, NOTE_G6, NOTE_G6, NOTE_G6, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E6, NOTE_F6, NOTE_C6, NOTE_FS5, NOTE_FS5, NOTE_FS6, NOTE_G6, NOTE_G6, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_AS3, NOTE_AS3, NOTE_AS3, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_CS4, NOTE_CS4, NOTE_G5, NOTE_G5, NOTE_AS6, NOTE_AS6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_G4, NOTE_F7, NOTE_F7, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_G5, NOTE_G6, NOTE_G4, NOTE_G4, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_GS5, NOTE_GS5, NOTE_G5, NOTE_G5, NOTE_G6, NOTE_GS6, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D7, NOTE_D7, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_B5, NOTE_B5, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_FS4, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_E6, NOTE_F6, NOTE_F6, NOTE_C6, NOTE_C6, NOTE_G4, NOTE_DS7, NOTE_DS7, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E6, NOTE_E6, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_DS5, NOTE_D5, NOTE_D5, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_DS5, NOTE_DS5, NOTE_G6, NOTE_G6, NOTE_DS5, NOTE_E4, NOTE_E4, NOTE_B6, NOTE_B6, NOTE_B6, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_B6, NOTE_B6, NOTE_AS6, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_B6, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_DS7, NOTE_B7, NOTE_F4, NOTE_F4, NOTE_AS7, NOTE_AS7, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_B7, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_FS4, NOTE_FS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_C6, NOTE_C6, NOTE_A5
};


unsigned char emoteData[] = { 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x3f,0xff,0xff,0xff,0xe0,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0f,0xff,0xff,0xff,0x80,0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x00,0x03,0xff,0xff,0xff,0x00,0x00,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x00,0x01,0xff,0xff,0xfe,0x00,0xf8,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x3e,0x00,0xff,0xff,0xfc,0x00,0xfc,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x7e,0x00,0x7f,0xff,0xfc,0x00,0xfe,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xfe,0x00,0x7f,0xff,0xf8,0x00,0x7f,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xfc,0x00,0x3f,0xff,0xf8,0x00,0x7f,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe1,0xfc,0x00,0x3f,0xff,0xf0,0x00,0x7f,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,0xfc,0x00,0x1f,0xff,0xf0,0x00,0x7f,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,0xfc,0x00,0x1f,0xff,0xf0,0x00,0x3f,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xf8,0x00,0x1f,0xff,0xf0,0x00,0x1f,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xf0,0x00,0x1f,0xff,0xf0,0x00,0x0f,0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc3,0xe0,0x00,0x1f,0xff,0xf0,0x00,0x00,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x1f,0xff,0xf8,0x00,0x00,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x00,0x00,0x3f,0xff,0xf8,0x00,0x18,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x30,0x00,0x3f,0xff,0xfc,0x00,0x3c,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x78,0x00,0x7f,0xff,0xf8,0x00,0x7c,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x7c,0x00,0x3f,0xff,0xf0,0x00,0x7c,0x3f,0xfe,0x7f,0xe0,0x07,0xfe,0x7f,0xff,0xf8,0x7c,0x00,0x1f,0xff,0xe1,0x00,0x00,0x7f,0xfe,0x7f,0xe0,0x07,0xfe,0x7f,0xff,0xfc,0x00,0x01,0x0f,0xff,0xc3,0x80,0x00,0xff,0xff,0xcf,0xe0,0x07,0xf3,0xff,0xff,0xfe,0x00,0x03,0x87,0xff,0xc7,0x80,0x03,0xff,0xf9,0xcf,0xe0,0x07,0xf3,0x9f,0xff,0xff,0x80,0x03,0xc7,0xff,0xff,0x88,0x0f,0xff,0xf9,0xff,0xf0,0x0f,0xff,0x9f,0xff,0xff,0xe0,0x23,0xff,0xff,0xff,0x9e,0x7f,0xff,0xff,0xff,0xfc,0x3f,0xff,0xff,0xff,0xff,0xfc,0xf3,0xff,0xff,0xff,0xfe,0x7f,0xff,0xff,0xff,0xfc,0x3f,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x9f,0xf8,0x1f,0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8f,0xe0,0x07,0xf1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x87,0x81,0x81,0xe1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x07,0xe0,0x03,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x1f,0xf8,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff };
const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

const int led = LED_BUILTIN;

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) { message += " " + server.argName(i) + ": " + server.arg(i) + "\n"; }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void handle_screen_write(){
  const char* plain = server.arg(0).c_str();
  write_text(CHP plain, 1 , 0 , 24 );
}

void handle_screen_draw(){
  const char* plain = server.arg(0).c_str();
  draw_screen(CHP plain);
  server.send(200 , "text/plain" , "request alindi");
}

// void handle_animation_draw(){
//   if(server.hasArg("plain")){
//     emoteData = server.arg("plain");
//     Serial.println("veri alindi:");
//     Serial.println(emoteData);
//     decodeBase64AndDisplay(emoteData);
//     server.send(200 , "text/plain" , "Veri alindi");
//   }else{
//     server.send(400 , "text/plain" , "veri gönderilemedi");
//   }
// }



void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  init_screen();
  play_buzzer(melody, 11 , 1851);
  WiFi.begin(ssid, password);
  Serial.println("");
  draw_screen_bitmap(emoteData);


  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) { Serial.println("MDNS responder started"); }

  server.on("/screen/write/", HTTP_POST , handle_screen_write);

  server.on("/screen/draw/", HTTP_POST, handle_screen_draw);

  // server.on("/upload/" , HTTP_POST , handle_animation_draw);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {

  server.handleClient();

}