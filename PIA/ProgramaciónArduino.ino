#include <LiquidCrystal.h>
#include <Servo.h>
#define Pecho 13
#define Ptrig 12

long duracion, distancia;

Servo servomotor1; //servo base

int eem = 100; // espera entre movimientos en ms
int vdm = 40; // velocidad de movimiento en ms
int tdc = 0; // tendon contraido, grado del servo
int tdr = 180; // tendon relajado, grado del servo
int dmax = 20; //distancia comienza a sensar, en cm
int dmin = 2; //distancia minima antes del toque
int dact; //distancia actual
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  Serial. begin(9600); //inicia puerto serial
  // configurar pines
  servomotor1.attach(9); //pin9 para señal de servo
  pinMode(Pecho, INPUT); //pin6 para entrada (echo)
  pinMode(Ptrig, OUTPUT); //pin7 para salida (triger)
  lcd.begin(16,2);
  }

void loop() {
  digitalWrite(Ptrig, LOW );  //----------------
  delayMicroseconds(2);     // genera el pulso
  digitalWrite(Ptrig, HIGH);// del triger por
  delayMicroseconds(10);    // 10 ms
  digitalWrite(Ptrig, LOW); //-----------------

  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion * 0.034)/ 2; //calcula la distancia en cm
  lcd.setCursor(0,0);
  lcd.print("Distancia:");
  lcd.print(distancia);
  lcd.print(" cm  ");

  if(distancia >= dmax){
    Serial.println("---");
    distancia = dmax;
    servomotor1.write(tdr); //dedo relajado
    
  }
  else{
    dact = distancia * 180 / dmax;
     Serial.print(distancia);  // muestra la distancia
    Serial.println(" cm");    // en cm y contrae el dedo
    
    servomotor1.write(dact);

  }
 
  delay(eem);

}
