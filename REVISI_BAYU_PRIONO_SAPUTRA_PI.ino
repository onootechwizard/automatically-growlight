#include <LiquidCrystal.h>//
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int LDR_Sensor = A0;  //LDR Sensor Pin
const int relay = 8; // Out for light 

int read_ADC =0;
int Brightness;

void setup(){

pinMode(LDR_Sensor, INPUT);
pinMode(relay, OUTPUT);

lcd.begin(16,2);  
lcd.setCursor(0,0);
lcd.print("Nama:Bayu Priono.S");
lcd.setCursor(0,1);
lcd.print("NPM :11418379");
Serial.begin(9600);
delay(5000); // Waiting for a while
lcd.clear();
}

void loop(){     
unsigned int read_ADC;
read_ADC = analogRead(LDR_Sensor); // read analogue to digital value 0 to 1023
Brightness = read_ADC /10.23; // Maximum value analogue to digital 1023 / 10.23

lcd.setCursor(0, 0);
lcd.print("Brightness: ");
lcd.print(Brightness);
lcd.print("%");
lcd.setCursor(0,1); 
lcd.print("Light is  : ");
Serial.println(read_ADC);

if(Brightness<25){digitalWrite(relay,HIGH); lcd.print(" On");}
if(Brightness>25){digitalWrite(relay,LOW);  lcd.print("Off");}

delay(100); 
}
