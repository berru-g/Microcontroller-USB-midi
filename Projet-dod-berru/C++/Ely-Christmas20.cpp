// JOUER DU PIANO SUR DES PATATES + led relié à HC-SR04 pour la mesure de distance
// 2 ANS DE MA BABY LOVE 2019
//Monter sur breadboard avec AtMéga 328p + oscillateur 16mhZ

#define ledR 13 //Led
#define ledB 12 //Led
#define ledV 11 //Led

void setup () {
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  pinMode(A0,INPUT); 
  //  Trig = 3;
  //  Echo = 4
  pinMode (9, OUTPUT);// buzzer
  pinMode (2,OUTPUT);//attach pin 2 to vcc
  pinMode (5,OUTPUT);//attach pin 5 to GND
  pinMode(ledR, OUTPUT); //On défini la led comme une sortie
  pinMode(ledB, OUTPUT);
  pinMode(ledV, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int fruit = analogRead(A5);
  int pomme = analogRead(A4);
  int fraise = analogRead(A3);
  int banane = analogRead(A2);
  int pattate = analogRead(A1);
  int cerise = analogRead(A0);



if(fruit<900){
  
  tone(9,262);
  delay(500);noTone(9);
  digitalWrite(ledR,HIGH);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,LOW);
}

if(pomme<900){
 
  tone(9,294);
  delay(500);noTone(9);
  digitalWrite(ledR,LOW);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,LOW);
}

if(fraise<900){
  
  tone(9,331);
  delay(500);noTone(9);
   digitalWrite(ledR,LOW);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,HIGH);
}

if(banane<900){
  
  tone(9,348);
  delay(500);noTone(9);
  digitalWrite(ledR,HIGH);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,LOW);
}

if(pattate<900){
  
  tone(9,392);
  delay(500);noTone(9);
  digitalWrite(ledR,LOW);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,LOW);
}

if(cerise<900){
  
  tone(9,441);
  delay(500);noTone(9);
   digitalWrite(ledR,LOW);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,HIGH);
}

   noTone(9);
  Serial.println(fruit);
  Serial.println(pomme);
  Serial.println(fraise);
  Serial.println(banane);
  Serial.println(pattate);
  Serial.println(cerise);
/////////TESTE THEREMIN////////////////////
{
digitalWrite(2, HIGH);
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(3, OUTPUT);// attach pin 3 to Trig
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(5);
  digitalWrite(3, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (4, INPUT);//attach pin 4 to Echo
  duration = pulseIn(4, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);

  int toneToPlay = 0;
  
  if(cm <= 160 && cm > 140)
  {
     toneToPlay = 523;
     digitalWrite(ledR,HIGH);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,LOW);
     delay(5);
       digitalWrite(ledR,LOW);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,LOW);
     delay(5);
     digitalWrite(ledR,LOW);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,HIGH);
  }
  if(cm <= 140 && cm > 120)
  {
     toneToPlay = 493;
     digitalWrite(ledR,LOW);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,LOW); 
  }
  if(cm <= 120 && cm > 100)
  {
     toneToPlay = 440;
     digitalWrite(ledR,LOW);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,HIGH); 
  }
  if(cm <= 100 && cm > 80)
  {
     toneToPlay = 392;
     digitalWrite(ledR,HIGH);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,LOW); 
  }
  if(cm <= 80 && cm > 60)
  {
     toneToPlay = 349;
     digitalWrite(ledR,LOW);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,HIGH); 
  }
  if(cm <= 60 && cm > 40)
  {
     toneToPlay = 329;
     digitalWrite(ledR,HIGH);
     digitalWrite(ledB,LOW);
     digitalWrite(ledV,HIGH); 
  }
  if(cm <= 40 && cm > 20)
  {
     toneToPlay = 294;
     digitalWrite(ledR,HIGH);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,LOW); 
  }
  if(cm <= 20)
  {
     toneToPlay = 261;
     digitalWrite(ledR,HIGH);
     digitalWrite(ledB,HIGH);
     digitalWrite(ledV,HIGH); 
  }
  
  if (toneToPlay == 0)
  {
    noTone(9);
  }
  else
  {
    tone(9, toneToPlay, 200);
  }
  
  //if you want the sound to just change based on distance, 
  //but not necessarily have frequencies that correspond 
  //to notes on a piano you can do this instead
  //tone(9, in*10, 200); 
  
  delay(100);
}
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
////////////////////////////

  