#include "InitFonction.h"

void init(void)
{
  pinMode(CAZ1, INPUT); 
  pinMode(CEL1, INPUT);  
  pinMode(CAZ2, INPUT);  
  pinMode(CEL2, INPUT);  
  pinMode(CURSEUR,INPUT);
  pinMode(SLEEP2, OUTPUT);
  pinMode(RESET2, OUTPUT);
  pinMode(MS1_2, OUTPUT);
  pinMode(MS2_2, OUTPUT);
  pinMode(MS3_2, OUTPUT);
  digitalWrite(MS1_2, HIGH);
  digitalWrite(MS2_2, HIGH);
  digitalWrite(MS3_2, HIGH);
  digitalWrite(SLEEP2, HIGH);
  digitalWrite(RESET2, HIGH);
}