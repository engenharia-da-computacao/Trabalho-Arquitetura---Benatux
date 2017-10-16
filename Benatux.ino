#include <Servo.h> // servo library 

//Mario main theme melody
////////
//
int speakerPin = 12;
//

Servo myservo[9];
int armazenaGrau[9];
int grau;
int servo;

String grauString = "";
String servoString = "";

/////
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};
//////

/////
//
#define cd 261
#define dc 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

//
void setup() { 
  
  pinMode(speakerPin, OUTPUT);
  
  int attachVar = 4;
  for(int i = 1; i <=8; ++i){
    myservo[i].attach(attachVar);
    armazenaGrau[i]=90;
    mexeServo(i,90);
    attachVar++;
  }
  
  Serial.begin(9600);
}

void loop() {
  
  while (servoString == "" && grauString == ""){
    
    while(Serial.available()){ // the code here is for bluetooth
      delay(3);
      char d = Serial.read();
      servoString += d;
    }
    
    if(servoString =="10"|| servoString =="12" || servoString =="20" || servoString == "21" || servoString == "22" || servoString == "23" ||servoString =="42" || servoString == "99"){
      grauString = "0";
    }
    Serial.println(grauString);
    
    if(servoString.length() > 0){
      while(grauString == ""){
        while(Serial.available()){
          // the code here is for bluetooth
          delay(3);
          char c = Serial.read();
          grauString += c;    
        }
      }
    }
      
    
    
  
  }
  
  Serial.println("Grau: " + grauString);
  Serial.println("Servo: " + servoString);
  
  servo = servoString.toInt();
  grau = grauString.toInt();
  
  if(servo==10){
    inicial();
    
  }
  else if(servo==12){
    
    cumprimento();
    
  }
  else if(servo==20){  
    andar();
  }
  else if(servo == 22){
    mexeServo(1,130);
    mexeServo(3,50);

    mexeServo(4,20);
    mexeServo(7,90);
    march();
    inicial();
  }
  else if(servo == 21){
    agachar();
  }
  else if(servo == 23){
    mexeServo(1,130);
    mexeServo(3,50);

    mexeServo(2,160);
    mexeServo(6,90);
    marioBros();
    inicial();
  }
  else if(servo == 42){
   for(int i=1;i<9;i++){
     Serial.print(i);
     Serial.print("-");
     Serial.println(armazenaGrau[i]);
   } 
   delay(2000);
  } 
  else if(servo == 99){
    descansar();
  }
  else{ 
    mexeServo(servo,grau);
  }
  
  
  
  servoString = "";
  grauString = "";
  
}
void mexeServo(int servo,int grau){
  int pos;
  if(armazenaGrau[servo] <= grau){
    for(pos=armazenaGrau[servo];pos<=grau;pos++){ 
      myservo[servo].write(pos);
      delay(10);
    }
  }else{
    for(pos=armazenaGrau[servo];pos>=grau;pos--){ 
      myservo[servo].write(pos);
      delay(10);
    }
  }
  armazenaGrau[servo]=grau;
}

void cumprimento(){
    mexeServo(1,130);
    mexeServo(3,50);
    mexeServo(4,10);
    mexeServo(7,60);
    mexeServo(7,120);
    mexeServo(7,60);
    mexeServo(7,120);
    mexeServo(7,60);
    mexeServo(7,120);
    
    mexeServo(4,60);
    mexeServo(7,120);
    mexeServo(1,120);
    mexeServo(3,60);
}

void descansar(){
    mexeServo(1, 0);
    mexeServo(2, 0);
    mexeServo(3, 180);
    mexeServo(4, 180);
    mexeServo(6, 0);
    mexeServo(8, 180);
    mexeServo(5, 0);
    mexeServo(7, 180);
    
    
}

void andar(){
  int attachVar = 4;
    for(int i = 1; i <=4; ++i){
      mexeServo(i,90);
      attachVar++;
    }
    
    mexeServo(5,40);
    mexeServo(1, 130);
    //mexeServo(7, 150);
    //mexeServo(4, 60);
    //mexeServo(7, 120);
    mexeServo(8, 130);
    mexeServo(3, 50);
    //mexeServo(8, 120);
    mexeServo(5, 70);
    mexeServo(2, 120);
    
    inicial();
}

void agachar(){
    mexeServo(1, 120);
    mexeServo(5, 60);
    mexeServo(3, 60);
    mexeServo(8, 120);
    mexeServo(4, 60);
    mexeServo(7, 120);
    mexeServo(2, 120);
    mexeServo(6, 60);
    mexeServo(1, 140);
    mexeServo(5, 40);
    mexeServo(3, 40);
    mexeServo(8, 140);
    mexeServo(4, 40);
    mexeServo(7, 140);
    mexeServo(2, 140);
    mexeServo(6, 40);
}

void inicial(){
    mexeServo(4,60);
    mexeServo(2,120);
    mexeServo(1,120);
    mexeServo(3,60);
    mexeServo(5,50);
    mexeServo(6,60);
    mexeServo(7,120);
    mexeServo(8,120);
}


//
void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)
{ 
    //digitalWrite(ledPin, HIGH);
    myservo[7].write(120);	     
    
    int x; 	 
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++) 	 
    { 	 
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(speakerPin,LOW);
        delayMicroseconds(delayAmount);
    } 	 
    
    //digitalWrite(ledPin, LOW);
     myservo[7].write(60);
    //set led back to low
    
    delay(20);
    //a little delay to make all notes sound separate
} 	 
  	 
void march()
{ 	 
    //for the sheet music see:
    //http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
    //this is just a translation of said sheet music to frequencies / time in ms
    //used 500 ms for a quart note
    
    beep(speakerPin, a, 500); 
    beep(speakerPin, a, 500);     
    beep(speakerPin, a, 500); 
    beep(speakerPin, f, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, a, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    //first bit
    
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);    
    beep(speakerPin, fH, 350); 
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, gS, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    //second bit...
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);  
    //start of the interesting bit
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 125);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, a, 125); 
    
    beep(speakerPin, cH, 500); 
    beep(speakerPin, a, 375);  
    beep(speakerPin, cH, 125); 
    beep(speakerPin, eH, 1000); 
    //more interesting stuff (this doesn't quite get it right somehow)
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350); 
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 250); 
    beep(speakerPin, gH, 250);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 250);  
    beep(speakerPin, cSH, 250);  
    //repeat... repeat
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
    beep(speakerPin, f, 250);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, cH, 125); 
           
    beep(speakerPin, a, 500);            
    beep(speakerPin, f, 375);            
    beep(speakerPin, cd, 125);            
    beep(speakerPin, a, 1000);       
    //and we're done \ó/    
}

/////
void marioBros(){
  //sing the tunes
  sing(1);
  sing(1);
  sing(2);
}
int song = 0;

void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];
 
      buzz(underworld_melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(0, noteDuration);
 
    }
 
  } else {
 
    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];
 
      buzz(melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(0, noteDuration);
 
    }
  }
}
 
void buzz(long frequency, long length) {
  myservo[6].write(60);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(speakerPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(speakerPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  myservo[6].write(120);
 
}
