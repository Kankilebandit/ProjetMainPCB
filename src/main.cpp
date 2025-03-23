#include <Arduino.h>
#include "definePIN.h"
#include <AccelStepper.h>
#include "InitFonction.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Fonts/FreeMonoBold12pt7b.h> // Add a custom font
#include <Fonts/FreeMono9pt7b.h>      // Add a custom font
#include "controleurBouton.h"
#include "variableGlob.h"

AccelStepper azimuthMotor(motorInterfaceType, STEP2, DIR2);
AccelStepper elevationMotor(motorInterfaceType, STEP1, DIR1);
TwoWire myWire = TwoWire(0);
Adafruit_SSD1306 display(128, 64, &myWire, -1); 

bool testI2CDevice(uint8_t address) {
  Wire.beginTransmission(address);
  return (Wire.endTransmission() == 0);
}

void setup()
{
  Serial.begin(115200); // Initialise la communication série à 115200 bauds
  Serial.println("Bonjours, je suis le moniteur!");
  init();
  
  azimuthMotor.setMaxSpeed(1000);
  azimuthMotor.setAcceleration(50);
  azimuthMotor.setSpeed(200);
  azimuthMotor.moveTo(10000);

  elevationMotor.setMaxSpeed(1000);
  elevationMotor.setAcceleration(50);
  elevationMotor.setSpeed(200);
  elevationMotor.moveTo(10000);
  /*Wire.begin();
  if (!testI2CDevice(SCREEN_ADDRESS)) {
      Serial.println("⚠️ Aucune réponse de l'écran OLED !");
      while (1);
  }


  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println("⚠️ Écran OLED non détecté !");
    while (1);
  }
  Serial.println("✅ Écran OLED détecté !");
  display.clearDisplay();      // Clear the buffer
  display.setTextColor(WHITE); // Set color of the text
  display.setRotation(0);      // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
  display.dim(0); // Set brightness (0 is maximun and 1 is a little dim)          // Set brightness (0 is maximun and 1 is a little dim)*/
}

void loop()
{
  //lireBouton();
  if (azimuthMotor.distanceToGo() == 0) {
    azimuthMotor.setCurrentPosition(0);
		azimuthMotor.moveTo(10000);
  }
	// Move the motor one step
	azimuthMotor.run();

  if (elevationMotor.distanceToGo() == 0) {
    elevationMotor.setCurrentPosition(0);
		elevationMotor.moveTo(10000);
  }
	// Move the motor one step
	elevationMotor.run();

 /* display.clearDisplay();           // Clear the display so we can refres
  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0);           // Set text size. We are using a custom font so you should always use the text size of 0
  display.setFont(&FreeMonoBold12pt7b);   // Set a custom font
  display.setCursor(50,0 );   // (x,y)
  display.println("Hello");  // Text or value to print
  display.setCursor(50, 17);   // (x,y)
  display.println("Wassim");  // Text or value to print
  //display.fillRect(0, 0, 117 ,  valeurConvertie, SSD1306_WHITE); // (x, y, largeur, hauteur, couleur) 118 et 65 de taille au complet 16 Jaune
  display.display();*/

 /* switch(state) {
    case DEMARRAGE :
      Serial.println("Case 0");
      break;
    case SUIVIE:
      Serial.println("Case 1");
      break;
    case CALIBRATION:
      Serial.println("Case 2");
      break;
    case FREE: 
      Serial.println("Case 3");
      break;
    default:
      Serial.println("etat autre");
      break;
  }*/
}
