//#include <Time.h>
//#include <TimeLib.h>

#include <Wire.h>
#include "RTClib.h"

#define rele 7

RTC_DS1307 rtc;
DateTime hoy;

////////VARIABLES GLOBALES//////////
int bandera_riego=0;
int bandera_verano=0;

int duracion_riego=10000;

int horariego1=7;
int horariego2=12;
int horariego3=18;
int horariegoextra=22;
//int hora_actual;
int ano,mes,dia,hora,minuto,segundo;

String DiasdelaSemana[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String MesesdelAno[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };

void riego_automatico(void);

//////Configuracion del reloj///////
//SDA A4 Línea I2C de transmisión de datos
//SCL A5 Línea I2C de la señal de reloj
//GND GND 
//VCC VCC
//SQW Este pin sirve para obtener una señal cuadrada, como no lo usaremos no lo declaramos

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  
  if (! rtc.isrunning()) {
    Serial.println("No se ha iniciado correctamente el módulo RTC");
    //ESTAS LINEAS SOLO SE USARÁN EN CASO DE QUE VAYAMOS A CARGAR EL CÓDIGO POR PRIMERA VEZ EN EL ARDUINO.
    //UNA VEZ SE HAYA COMPILADO UNA VEZ, DEBREMOS COMENTAR LA LINEA Y VOLVER A SUBIRLO
    //ESTA SENTENCIA ES PARA ESTABLECER LA HORA ACTUAL MEDIANTE LA HORA DE NUESTRO ORDENADOR
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    rtc.adjust(DateTime(2020, 11, 21, 19, 0, 0));
  }

  //Definimos los puertos
  pinMode(rele, OUTPUT);///Puerto del relé
  

}

void loop() {
  hoy = rtc.now();///Recuperamos la fecha actual y la imprimos por serial
  
  ano=hoy.year();
  mes=hoy.month();
  dia=hoy.day();
  hora=hoy.hour();
  minuto=hoy.minute();
  segundo=hoy.second();
  
  Serial.print(ano);
  Serial.print('/');
  Serial.print(mes);
  Serial.print('/');
  Serial.print(dia);
  //Serial.print('(');
  //Serial.print(DiasdelaSemana[hoy.dayOfTheWeek()]);
  //Serial.print(')');
  Serial.print(' ');
  Serial.print(hora);
  Serial.print(':');
  Serial.print(minuto);
  Serial.print(':');
  Serial.print(segundo);
  Serial.println();
  
  riego_automatico();

  
}

void riego_automatico(){
  if(mes==6||mes==7||mes==8)
  {
    bandera_verano=1;
  }
  else bandera_verano=0;

  if((hora==horariego1||hora==horariego2||hora==horariego3)&&bandera_riego==0)
  {
    bandera_riego=1;
    digitalWrite(rele, LOW);///CREO QUE MI RELE SE ACTIVA EN BAJA
    Serial.print("Regando a las ");
    Serial.println(hora);
    delay(duracion_riego);
    digitalWrite(rele,HIGH);
  }
  if((hora==(horariego1+1)||hora==(horariego2+1)||hora==(horariego3+1)||hora==(horariegoextra+1)))
  {
    bandera_riego=0;
  }
  if(bandera_verano==1&&hora==horariegoextra&&bandera_riego==0)
  {
    bandera_riego=1;
    digitalWrite(rele, LOW);///CREO QUE MI RELE SE ACTIVA EN BAJA
    Serial.print("Regando a las ");
    Serial.println(hora);
    Serial.println(":");
    Serial.println(minuto);
    Serial.println(":");
    Serial.println(segundo);
  }
}
