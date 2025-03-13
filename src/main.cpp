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

AccelStepper myStepper(motorInterfaceType, STEP2, DIR2);
TwoWire myWire = TwoWire(0);
Adafruit_SSD1306 display(128, 64, &myWire, -1); // Create display



void setup()
{
  Serial.begin(115200); // Initialise la communication série à 115200 bauds
  Serial.println("Bonjours, je suis le moniteur!");
  init();
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(50);
  myStepper.setSpeed(200);
  myStepper.moveTo(1000);

  myWire.begin(SDAPIN, SDLPIN);

  // Vérifier la connexion I2C
  Serial.println("Scan I2C...");
  for (uint8_t addr = 1; addr < 127; addr++)
  {
    myWire.beginTransmission(addr);
    if (myWire.endTransmission() == 0)
    {
      Serial.print("Device found at 0x");
      Serial.println(addr, HEX);
    }
  }

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println("⚠️ Écran OLED non détecté !");
    while (1)
      ;
  }
  Serial.println("✅ Écran OLED détecté !");
  display.clearDisplay();      // Clear the buffer
  display.setTextColor(WHITE); // Set color of the text
  display.setRotation(0);      // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.
                               // To override this behavior (so text will run off the right side of the display - useful for
                               // scrolling marquee effects), use setTextWrap(false). The normal wrapping behavior is restored
                               // with setTextWrap(true).

  display.dim(0); // Set brightness (0 is maximun and 1 is a little dim)
}

void loop()
{
  lireBouton();
  printf("caz1:%x,cel1:%x,caz2:%x,cel2:%x\n\r", etatCAZ1, etatCEL1, etatCAZ2,etatCEL2);
  int valeurBrute = analogRead(CURSEUR);  // Lecture de la valeur entre 0 et 4095
  int valeurConvertie = map(valeurBrute, 0, 4095, 0, 20);  // Conversion en 0-20
  Serial.println(valeurConvertie);  // Affichage dans le moniteur série

  /*if (myStepper.distanceToGo() == 0)
    myStepper.moveTo(-myStepper.currentPosition())
  // Move the motor one step
  myStepper.run();*/

  display.clearDisplay();           // Clear the display so we can refres
  //display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0);           // Set text size. We are using a custom font so you should always use the text size of 0
  //display.setFont(&FreeMonoBold12pt7b);   // Set a custom font
  // Print variable with left alignment:
  display.setCursor(50,0 );   // (x,y)
  display.println("Hello");  // Text or value to print
  display.setCursor(50, 17);   // (x,y)
  display.println("Wassim");  // Text or value to print
  //display.fillRect(0, 0, 117 ,  valeurConvertie, SSD1306_WHITE); // (x, y, largeur, hauteur, couleur) 118 et 65 de taille au complet 16 Jaune
  display.display();

}
