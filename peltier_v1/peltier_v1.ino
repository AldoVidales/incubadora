
//Autor:Aldo Vidales Rodríguez --- instagram:aldo_vidalesr 
//Fecha:21/2/2021

int cold_wind= 13;
int hot_wind=11;
int peltier =12;

void setup() {
  // put your setup code here, to run once:
pinMode(peltier,OUTPUT);//relevador que enciende peltier
pinMode(cold_wind,OUTPUT);//relevador que enciende avanico
pinMode(hot_wind,OUTPUT);//relevador que enciende peltier
Serial.begin(9600);//puerto serial



  

}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println("abanico prendido");
  digitalWrite(cold_wind,HIGH);
    digitalWrite(hot_wind,LOW);
   digitalWrite(peltier,LOW);//esta al reves
 
  delay(10000);
   Serial.println("abanico apagado");
  digitalWrite(cold_wind,LOW);
  digitalWrite(hot_wind,HIGH);
  digitalWrite(peltier,HIGH);
   
    delay(10000);
    

}
