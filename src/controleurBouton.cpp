#include "controleurBouton.h"


void lireBouton(void)
{
    delay(1000);
    etatCAZ1 = digitalRead(CAZ1);
    etatCEL1 = digitalRead(CEL1);
    etatCAZ2 = digitalRead(CAZ2);
    etatCEL2 = digitalRead(CEL2);
}