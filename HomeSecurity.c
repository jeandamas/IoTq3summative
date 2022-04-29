#include <LiquidCrystal.h>
//LEFT SENSOR
#define L_ECHO 9
#define L_TRIGGER 10
#define TIEMPO_MUESTREO 1000
#define PULSO_L_TRIGGER 1
//RIGHT SENSOR
#define R_ECHO 11
#define R_TRIGGER 12
#define TIEMPO_MUESTREO 1000
#define PULSO_R_TRIGGER 1
int DURATION;
int buzPin=13;

//LEFT DISTANCE
float L_DISTANCE;
//RIGHT DISTANCE
float R_DISTANCE;

float DISTUmb;
float LED;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int num=1;


void setup() {
  // set up the LCD's number of columns and rows:
  
  pinMode(L_TRIGGER, OUTPUT);
  pinMode(L_ECHO, INPUT);
  pinMode(buzPin,OUTPUT);
  pinMode(R_TRIGGER, OUTPUT);
  pinMode(R_ECHO, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("LEFT:");
  lcd.setCursor(0,1);
  lcd.print("RIGHT:");
}

void loop() {
  digitalWrite(buzPin,LOW);
  //LEFT
  digitalWrite(L_TRIGGER, HIGH);
  delay(PULSO_L_TRIGGER); 
  digitalWrite(L_TRIGGER, LOW);
  DURATION = pulseIn(L_ECHO,HIGH);
  //Distance IN METRES
  L_DISTANCE = DURATION*0.034/100;
  Serial.println(L_DISTANCE);
  
  //RIGHT
  digitalWrite(R_TRIGGER, HIGH);
  delay(PULSO_R_TRIGGER); 
  digitalWrite(R_TRIGGER, LOW);
  DURATION = pulseIn(R_ECHO,HIGH);
  //Distance IN METRES
  R_DISTANCE = DURATION*0.034/100;
  Serial.println(R_DISTANCE);
 
  if (L_DISTANCE<=1.5 || R_DISTANCE<=1.5)
{
  digitalWrite(buzPin, HIGH);

    if(L_DISTANCE<=1.5){
      lcd.setCursor(5, 0);
      lcd.print(float(L_DISTANCE));
      lcd.print("Stranger");
    }
    
    if(R_DISTANCE<=1.5){
      lcd.setCursor(6, 1);
      lcd.print(float(R_DISTANCE));
      lcd.print("Stranger");
    }
      //print warning in serior monitor
  Serial.print("Person on left");
  }else{
  lcd.setCursor(5, 0);
  lcd.print(float(L_DISTANCE));
     lcd.print(" safe"); 
    
   lcd.setCursor(6, 1);
  lcd.print(float(R_DISTANCE));
     lcd.print(" safe");
  }
  //left sensor
  //lcd.setCursor(5, 0);
  //lcd.print(float(L_DISTANCE));
  
  //right sensor
  //lcd.setCursor(6, 1);
  //lcd.print(float(R_DISTANCE));
  
  delay(TIEMPO_MUESTREO); 
  lcd.setCursor(13,0);
  lcd.print(" ");
  lcd.setCursor(13,1);
  lcd.print(" ");
  
}
 
