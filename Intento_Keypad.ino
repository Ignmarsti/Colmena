#include <Keypad.h>

const byte filas =4;
const byte columnas=4;
char teclas [filas][columnas] ={
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'}
  {'7', '8', '9', 'C'}
  {'*', '0', '#', 'D'} 
  };
byte pinesFilas [filas] = {7, 6, 5, 4};
byte pinesColumnas [columnas] = {3, 2, 1, 0};
char tecla_pulsada;
char horariego1[6];
char horariego2[6];
char horariego3[6];

/////////Objetos///////
Keypad teclado = Keypad(makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas]; ///Crea el mapa del teclado 
 
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  tecla_pulsada = teclado.getKey();
  if(tecla_pulsada='A')
  {
    int i=0;
    for(i=0, i<7, i++)
    {
      tecla_pulsada = teclado.getKey();
      horariego1[i]=tecla_pulsada;
    }
    if(horariego1[0]>2||horariego1[2]>6||horariego1[5]>6)
    {
      Serial.println("ERROR AL INTRODUCIR LA HORA");
    }
    else{
      Serial.print("Se ha programado la hora de riego a las ")
      Serial.print(horariego1[0], horariego1[1]):
      Serial.print(':');
      Serial.print(horariego1[2], horariego[3]);
      Serial.print(':');
      Serial.println(horariego1[4], horariego1[5]);
    }
  }

  if(tecla_pulsada='B')
  {
    int i=0;
    for(i=0, i<6, i++)
    {
      tecla_pulsada = teclado.getKey();
      horariego2[i]=tecla_pulsada;
    }
    if(horariego2[0]>2||horariego2[2]>6||horariego2[5]>6)
    {
      Serial.println("ERROR AL INTRODUCIR LA HORA");
    }
    else{
      Serial.print("Se ha programado la hora de riego a las ")
      Serial.print(horariego2[0], horariego2[1]):
      Serial.print(':');
      Serial.print(horariego2[2], horariego2[3]);
      Serial.print(':');
      Serial.println(horariego2[4], horariego2[5]);
    }
  }
  if(tecla_pulsada='C')
  {
    int i=0;
    for(i=0, i<6, i++)
    {
      tecla_pulsada = teclado.getKey();
      horariego3[i]=tecla_pulsada;
    }
    if(horariego3[0]>2||horariego3[2]>6||horariego3[5]>6)
    {
      Serial.println("ERROR AL INTRODUCIR LA HORA");
    }
    else{
      Serial.print("Se ha programado la hora de riego a las ")
      Serial.print(horariego3[0], horariego3[1]):
      Serial.print(':');
      Serial.print(horariego3[2], horariego3[3]);
      Serial.print(':');
      Serial.println(horariego3[4], horariego3[5]);
    }
  }

}
