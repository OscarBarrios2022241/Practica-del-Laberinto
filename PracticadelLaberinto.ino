//Oscar Jose Barrios Cotom - 2022241
//EB5AM

#include <Wire.h> //Libreria I2C
#include <Adafruit_Sensor.h> // Libreria para Acelerometro
#include <Adafruit_ADXL345_U.h> //Libreria para Acelerometro
#include <Servo.h>//Librerias

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(); //Coloco Nombre al Acelerometro
int Eje_X = 0; //Variable para la aceleracion en eje X
int Eje_Y = 0; //Variable para la aceleracion en eje Y
int Eje_Z = 0; //Variable para la aceleracion en eje Z
int servoPin1 = 9;//Servo1 al pin 9
int servoPin2 = 10;//Servo2 al pin 10
int X =0;//Variable X igualada a 0
int Y =0;//Variable Y igualada a 0
Servo servo;//Se nombra el servo que se va usar
Servo servo1;//Se nombra el servo que se va usar

void setup(void) {
Serial.begin(9600); //Inicializo el monitor serial a 9600bps
accel.begin();// Inicializo libreria del acelerometro
servo.attach(9);//Se coloca el pins al que va el servomotor
servo1.attach(10);//Se coloca el pine al que va el servomotor
}

void loop(void) {
sensors_event_t event; //Le coloco un nombre a las lecturas del acelerometro
accel.getEvent(&event); //los datos de las lecturas del acelerometro se pasan a la funcion que envia los datos
Eje_X = event.acceleration.x; //Asigna la lectura del acelerometro en el eje X
Eje_Y = event.acceleration.y; //Asigna la lectura del acelerometro en el eje Y
Eje_Z = event.acceleration.z; //Asigna la lectura del acelerometro en el eje Z
X = map(Eje_X,-10,9,-90,90);//La variable X se iguala a la variable MAP
servo.write(X);//El servo1 se mueve dependiendo la cantidad asignada en MAP
Y = map(Eje_Y,-3,3,-90,90);//La variable Y se iguala a la variable MAP
servo1.write(Y);//El servo2 se mueve dependiendo la cantidad asignada en MAP
Serial.print("X: "); Serial.println(X); Serial.print(" ");//Imprime los datos en el Eje X
Serial.print("Y: "); Serial.println(Y); Serial.print(" ");//Imprime los datos en el Eje Y


delay(100);//Delay general
}