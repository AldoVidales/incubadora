// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Leds.ino
    Created:	5/12/2021 11:28:10 AM
    Author:     Aldo Vidales
*/

// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int cold_wind = 13;
int hot_wind = 11;
int peltier = 12;
float regularTemp = 37.7;
const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;
void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("INTR MECATRONICA");

    pinMode(16, INPUT);
    pinMode(17, INPUT);
    pinMode(18, INPUT);
    pinMode(19, INPUT);

    pinMode(peltier, OUTPUT);//relevador que enciende peltier
    pinMode(cold_wind, OUTPUT);//relevador que enciende avanico
    pinMode(hot_wind, OUTPUT);//relevador que enciende peltier
    Serial.begin(9600);//puerto serial
}
float CheckTemp() 
{
    int value = analogRead(sensorPin1);
    float millivolts = (value / 1023.0) * 5000;
    float celsius = millivolts / 10;
    //keepTemp(celsius);
    return celsius;
}


void temp_UpDown(int fanId , bool setOn) {
    if (setOn == true) {

        digitalWrite(peltier, LOW);//esta al reves
        Serial.println(" abanico prendido");
        digitalWrite(fanId, HIGH);
    }
    else
    {
        digitalWrite(peltier, HIGH);//esta al reves
        Serial.println(" abanico apagado");
        digitalWrite(fanId, LOW);
    }

}

//
//void temp_Up(bool setOn) {
//    if (setOn == true) {
//
//        digitalWrite(peltier, LOW);//esta al reves
//        Serial.println("abanico prendido");
//        digitalWrite(hot_wind, HIGH);
//    }
//    else
//    {
//        digitalWrite(peltier, HIGH);//esta al reves
//        Serial.println("abanico apagado");
//        digitalWrite(hot_wind, LOW);
//    }
//
//}
//



bool warmIncubator()
{
    // PRENDE PELTIER Y ABANICO PARA CALENTAR
    temp_UpDown(hot_wind,true);
    float actualTemp = CheckTemp();

    while (regularTemp < actualTemp) {

        
        delay(10000);
        float actualTemp = CheckTemp();        
    }
    // APAGA PELTIER Y ABANICO PARA CALENTAR
    temp_UpDown(hot_wind, false);
    return true;
}
bool coldIncubator()
{
    // PRENDE PELTIER Y ABANICO PARA ENFRIAR
    temp_UpDown(cold_wind, true);
    float actualTemp = CheckTemp();
    while (regularTemp > actualTemp) {


        delay(10000);
        float actualTemp = CheckTemp();
    }
    // APAGA PELTIER Y ABANICO PARA ENFRIAR
    temp_UpDown(cold_wind, false);
   
    return true;
}
void  keepTemp(float TempActual)
{
    if (TempActual != regularTemp)
    {
        if (TempActual < regularTemp) {
            warmIncubator();
        }
        else{
            coldIncubator();
        }
    } 
}





void loop() {
    lcd.setCursor(2, 1);
    lcd.print(digitalRead(19));
    lcd.print(" ");
    lcd.print(digitalRead(18));
    lcd.print(" ");
    lcd.print(digitalRead(17));
    lcd.print(" ");
    lcd.print(digitalRead(16));
    //CheckTemp();
    keepTemp(CheckTemp());
    
}

//
//while (TempActual != regularTemp) {
//    if (TempActual < regularTemp) {
//
//
//        digitalWrite(peltier, LOW);//esta al reves
//        Serial.println("abanico prendido");
//        digitalWrite(hot_wind, HIGH);
//
//
//        Serial.println("abanico apagado");
//        delay(10000);
//
//        digitalWrite(hot_wind, LOW);
//
//
//    }
//    if (TempActual > regularTemp) {
//        digitalWrite(peltier, LOW);//esta al reves
//        Serial.println("abanico prendido");
//        digitalWrite(cold_wind, HIGH);
//
//        Serial.println("abanico apagado");
//        delay(10000);
//    }
//}