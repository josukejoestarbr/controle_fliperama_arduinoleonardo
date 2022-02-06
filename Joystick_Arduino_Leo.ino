//By Fillipe Welausen - 04/03/2020 - CircuitoMaker.com

#include "Joystick.h"

 Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  
  8, 2,                  // Button Count, Hat Switch Count
  true, true, true,      // X and Y, but no Z Axis
  true, true, false,     // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

int botoes1Pins[]={0,1,2,3};         //  A, B, X, Y
int ledsPins[]={A0,A1,A2,A3};        //  4 LEDS PARA OS BOTÕES DE ACRÍLICO (A, B, X, Y) 
int botoes2Pins[]={4,5,6,7};         //  L, R, START, SELECT
int direcionalPins[]={11,10,13,12};  //  DIREITA, ESQUERDA, BAIXO, CIMA

void setup(){

 for(int x=0; x<=3; x++)
 {
   pinMode(botoes1Pins[x],INPUT_PULLUP);    // Declara todos os pinos dos botoes 1 como entrada e ativa os resistores de "PULL UP" internos
   pinMode(botoes2Pins[x],INPUT_PULLUP);    // Declara todos os pinos dos botoes 2 como entrada e ativa os resistores de "PULL UP" internos
   pinMode(ledsPins[x],OUTPUT);             // Declara os pinos dos leds como saídas digitais
   pinMode(direcionalPins[x],INPUT_PULLUP); // Declara todos os pinos do direcional como entrada e ativa os resistores de "PULL UP" internos                
  }


  Joystick.begin(false); 
  Joystick.setXAxisRange (-127, 127);
  Joystick.setYAxisRange (-127, 127);
  
}// fim do setup


void loop(){
  

 for(int x=0; x<=3; x++){
   if(digitalRead(botoes1Pins[x])==LOW){ // Lê e "seta" valores dos botões 1
     Joystick.setButton(x, 1);  
     digitalWrite(ledsPins[x],LOW); // Desliga o led correspondente ao botão "pressionado"
   }
   else{
     Joystick.setButton(x, 0);  
     digitalWrite(ledsPins[x],HIGH);  // Liga o led correspondente ao botão "solto"
   }

 
    if(digitalRead(botoes2Pins[x])==LOW){ // Lê e "seta" valores dos botões 2
     Joystick.setButton(x+4, 1);  // x+4 equivale a 5, 6, 7 ou 8 dependendo do valor de x determinado pela rotina "FOR"
   }
   else{
     Joystick.setButton(x+4, 0);  
   }
 
 }//fim fo "for"




int Value_X1= 0;
int Value_Y1= 0; 

// Lê valores do direcional
  if(digitalRead(direcionalPins[0])==LOW){Value_X1=  127;}  // DIREITA
  if(digitalRead(direcionalPins[1])==LOW){Value_X1= -127;}  // ESQUERDA
  if(digitalRead(direcionalPins[2])==LOW){Value_Y1=  127;}  // BAIXO
  if(digitalRead(direcionalPins[3])==LOW){Value_Y1= -127;}  // CIMA
 
 Joystick.setXAxis(Value_X1);
 Joystick.setYAxis(Value_Y1);

 //Atualiza todos os Valores
  Joystick.sendState();
  delay(10); 

}// fim do loop
