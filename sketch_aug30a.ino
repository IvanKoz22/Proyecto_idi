#include <ESP8266WiFi.h>
// Definición de uso de los pines
const int ledPin = 2;
bool estadoBoton1 =  false;
bool estadoBoton2 = false;
bool estadoBoton3 = false;
bool estadoBoton4 = false;
bool estadoBoton5 = false;
bool estadoBoton6 = false;
bool estadoBoton7 = false;
int contador = 0;
void setup(){    
  // Activamosde los GPIO, el de entrada en modalidad PULL DOWN   
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);    
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, INPUT_PULLUP);    
  //pinMode(D5, INPUT_PULLUP);
  pinMode(D6, INPUT_PULLUP);    
  //pinMode(D7, INPUT_PULLUP);    
  pinMode(2, OUTPUT);
  Serial.begin(115200);
}
 void loop() {   
   // Leemos el estado del GPIO    
  estadoBoton1 = digitalRead(D1);   
  estadoBoton2 = digitalRead(D2);
   estadoBoton3 = digitalRead(D3);   
  estadoBoton4 = digitalRead(D4);
   estadoBoton5 = digitalRead(D5);   
  estadoBoton6= digitalRead(D6);
  //estadoBoton7 = digitalRead(D7);
  // Controlamos el led según el resultado  
  if (estadoBoton2 == HIGH) {    
    digitalWrite(ledPin, HIGH);
    contador = contador + 1;
  }  
  else {   
    digitalWrite(ledPin, LOW);
  }
  if ((estadoBoton1 == HIGH) && (contador>=1)){
  contador = contador - 1;
  }
  if (estadoBoton4 == HIGH) {    
    digitalWrite(ledPin, HIGH);
    contador = contador + 1;
  }  
  else {   
    digitalWrite(ledPin, LOW);
  }
  if ((estadoBoton3 == HIGH) && (contador>=1)){
  contador = contador - 1;
  }
   if (estadoBoton5 == HIGH) {   
    digitalWrite(ledPin, HIGH);
    //contador = contador + 1;
  }  
  else {   
    digitalWrite(ledPin, LOW);
  }
  if ((estadoBoton6 == LOW) && (contador>=1)){
  contador = contador - 1;
  }
   if ((estadoBoton7 == HIGH) && (contador>=1)){
  //contador = contador - 1;
  }

 
  Serial.println(contador);
  delay(1000);
}
