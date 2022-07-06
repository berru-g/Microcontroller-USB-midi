// MAIS CELUI CI CEST LE BON :)- MICROCONTROLLER- USB-MIDI + CLAVIER
//CODE N°24, CINQUIEME SEMAINE DE PROG 
//THANK "PretEnGineering" POUR LA STRUCTURE ;)
// BERRU ENLEVE TON FUCKING HAIRLESS AVANT DE COMPILER MERCI!!!!!!
#include <MIDI.h>
//#include <pitches.h>
MIDI_CREATE_DEFAULT_INSTANCE(); // DECLARATION PIN DIGITAL
int buttonZpin = 2;
int buttonApin = 3;  
int buttonBpin = 4;  
int buttonCpin = 5;   
int buttonDpin = 6;
int buttonEpin = 7;
int buttonFpin = 8;  
int buttonGpin = 9;  
int buttonHpin = 10;   
int buttonIpin = 11;
int buttonJpin = 12;
int buttonKpin = 13;
                        //DECLARATION PIN ANALOGIQUE
int analogpot1 = A0;  // POTARD 1
int analogpot2 = A1; 
int analogpot3 = A2; //°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot4 = A3; //°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot5 = A4; //°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot6 = A5;
                       //ROLE DES PIN ANALOGUE
int analogpot1Old = 0;
int analogpot2Old = 0;
int analogpot3Old = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot4Old = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot5Old = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot6Old = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot1New = 0;
int analogpot2New = 0;
int analogpot3New = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot4New = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot5New = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°
int analogpot6New = 0;//°°°°°°°°°°°°°°°°°°°°°°°°°°°

                       // VALEUR DES PIN ANALOGUE = RECONNU POUR LE MAPPAGE ABLETON COMME " C-54 " & " C-55 " ETC...
#define analogpot1CC 54
#define analogpot2CC 55
#define analogpot3CC 56//°°°°°°°°°°°°°°°°°°°°°°°°°°
#define analogpot4CC 57//°°°°°°°°°°°°°°°°°°°°°°°°°°
#define analogpot5CC 58//°°°°°°°°°°°°°°°°°°°°°°°°°°
#define analogpot6CC 59//°°°°°°°°°°°°°°°°°°°°°°°°°°

void setup() {
  
MIDI.begin ();        // ETAT DES PIN DIGITAL

pinMode(buttonZpin, INPUT_PULLUP);// UTILISE LA RESISTANCE DE LA CARTE // A ENLEVER SI RESISTANCE // ATTENTION AU CHANGEMENT DE BRANCHEMENT DES BOUTTON !!!
pinMode(buttonApin, INPUT_PULLUP);
pinMode(buttonBpin, INPUT_PULLUP);
pinMode(buttonCpin, INPUT_PULLUP);
pinMode(buttonDpin, INPUT_PULLUP);
pinMode(buttonEpin, INPUT_PULLUP);
pinMode(buttonFpin, INPUT_PULLUP);
pinMode(buttonGpin, INPUT_PULLUP);
pinMode(buttonHpin, INPUT_PULLUP);
pinMode(buttonIpin, INPUT_PULLUP);
pinMode(buttonJpin, INPUT_PULLUP);
pinMode(buttonKpin, INPUT_PULLUP);

pinMode(analogpot1, INPUT);
pinMode(analogpot2, INPUT);
pinMode(analogpot3, INPUT);
pinMode(analogpot4, INPUT);
pinMode(analogpot5, INPUT);
pinMode(analogpot6, INPUT);
Serial.begin(9600); //
//Serial.begin(115200);
}

void loop() {
                                   // ETAT ACTUEL DES PIN ANALOGUE
static bool buttonZvalueOld = HIGH;
static bool buttonAvalueOld = HIGH;
static bool buttonBvalueOld = HIGH;
static bool buttonCvalueOld = HIGH;
static bool buttonDvalueOld = HIGH;
static bool buttonEvalueOld = HIGH;
static bool buttonFvalueOld = HIGH;
static bool buttonGvalueOld = HIGH;
static bool buttonHvalueOld = HIGH;
static bool buttonIvalueOld = HIGH;
static bool buttonJvalueOld = HIGH;
static bool buttonKvalueOld = HIGH;

bool buttonZvalueNew = digitalRead(buttonZpin);
bool buttonAvalueNew = digitalRead(buttonApin);
bool buttonBvalueNew = digitalRead(buttonBpin);
bool buttonCvalueNew = digitalRead(buttonCpin);
bool buttonDvalueNew = digitalRead(buttonDpin);
bool buttonEvalueNew = digitalRead(buttonEpin);
bool buttonFvalueNew = digitalRead(buttonFpin);
bool buttonGvalueNew = digitalRead(buttonGpin);
bool buttonHvalueNew = digitalRead(buttonHpin);
bool buttonIvalueNew = digitalRead(buttonIpin);
bool buttonJvalueNew = digitalRead(buttonJpin);
bool buttonKvalueNew = digitalRead(buttonKpin);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NOTE SANS LES DIESES | RANGEE PAR 2 OCTAVES, SOIT LA CAPACIT2 DU CLAVIER MIDI BOIS                            //
//       OCTAVE +              28 30 32 33 35 37 39 40 42 44 45 47 48 49 51    FREQUENCES BASSES = NOTES GRAVES //
//       OCTAVES EN PROG       52,54,56,57,59,61,63||,64,66,68,69,71,73,75                                        //
//       OCTAVE -              64 66 68 69 71 73 75 76 ||78 80 81 83 85 87 88    FREQUENCES HAUTES = NOTES AIGUES //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

         if (buttonZvalueNew != buttonZvalueOld){
      if (buttonZvalueNew == LOW){
      MIDI.sendNoteOn(52, 127, 1);
      Serial.println("Note Z On");
      }
      else {
      MIDI.sendNoteOff(52, 0, 1);
      Serial.println("Note Z Off");
      }
      
      buttonZvalueOld = buttonZvalueNew;
    }///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    if (buttonAvalueNew != buttonAvalueOld){ /////////////////////////////////////////PREMIERE NOTE/////////////////////////////////////////////////////////////
      if (buttonAvalueNew == LOW){  // SI J APPUIE ...|`||METTRE A L ETAT "HIGH" SI RESISTANCES, ET BRANCHEZ AU GROUND LE BOUTON;) ET ENLEVER INPUT_PULLUP DANS LA DECLARATION
      MIDI.sendNoteOn(54, 127, 1); //  (NUM NOTE,VELOCITE,ETAT?)
      Serial.println("Note A On");
      }
      else {
      MIDI.sendNoteOff(54, 0, 1);
      Serial.println("Note A Off");
      }
      buttonAvalueOld = buttonAvalueNew;
    }//////////////////////////////////////////////////////////////////////////// B ///////////////////////////////////////////////////////////////////////////////

      if (buttonBvalueNew != buttonBvalueOld){
      if (buttonBvalueNew == LOW){
      MIDI.sendNoteOn(56, 127, 1);
      Serial.println("Note B On");
      }
      else {
      MIDI.sendNoteOff(56, 0, 1);
      Serial.println("Note B Off");
      }
      buttonBvalueOld = buttonBvalueNew;
    }//////////////////////////////////////////////////////////////////////////// C /////////////////////////////////////////////////////////////////////////

      if (buttonCvalueNew != buttonCvalueOld){
      if (buttonCvalueNew == LOW){
      MIDI.sendNoteOn(57, 127, 1);
      Serial.println("Note C On");
      }
      else {
      MIDI.sendNoteOff(57, 0, 1);
      Serial.println("Note C Off");
      }
      buttonCvalueOld = buttonCvalueNew;
    }//////////////////////////////////////////////////////////////////////////// D ///////////////////////////////////////////////////////////////////////
    
      if (buttonDvalueNew != buttonDvalueOld){
      if (buttonDvalueNew == LOW){
      MIDI.sendNoteOn(59, 127, 1);
      Serial.println("Note D On");
      }
      else {
      MIDI.sendNoteOff(59, 0, 1);
      Serial.println("Note D Off");
      }
      buttonDvalueOld = buttonDvalueNew;
    }/////////////////////////////////////////////////////////////////////////// E /////////////////////////////////////////////////////////////////////
    
      if (buttonEvalueNew != buttonEvalueOld){
      if (buttonEvalueNew == LOW){
      MIDI.sendNoteOn(61, 127, 1);
      Serial.println("Note E On");
      }
      else {
      MIDI.sendNoteOff(61, 0, 1);
      Serial.println("Note E Off");
      }
      buttonEvalueOld = buttonEvalueNew;
      }
///////////////////////////////////////////52,54,56,57,59,61,63,64,66,68,69,71,73,75//////// F ///////////////////////////////////////////////////////////
 if (buttonFvalueNew != buttonFvalueOld){
      if (buttonFvalueNew == LOW){
      MIDI.sendNoteOn(63, 127, 1);
      Serial.println("Note F On");
      }
      else {
      MIDI.sendNoteOff(63, 0, 1);
      Serial.println("Note F Off");
      }
      buttonFvalueOld = buttonFvalueNew;
    }//////////////////////////////////////////////////////////////////////// G ///////////////////////////////////////////////////////////////////////////

      if (buttonGvalueNew != buttonGvalueOld){
      if (buttonGvalueNew == LOW){
      MIDI.sendNoteOn(64, 127, 1);
      Serial.println("Note G On");
      }
      else {
      MIDI.sendNoteOff(64, 0, 1);
      Serial.println("Note G Off");
      }
      buttonGvalueOld = buttonGvalueNew;
    }////////////////////////////////////////////////////////////////////////////// H //////////////////////////////////////////////////////////////////////

// 64,66,68,69,71,73,75
      if (buttonHvalueNew != buttonHvalueOld){
      if (buttonHvalueNew == LOW){
      MIDI.sendNoteOn(66, 127, 1);
      Serial.println("Note H On");
      }
      else {
      MIDI.sendNoteOff(66, 0, 1);
      Serial.println("Note H Off");
      }
      buttonHvalueOld = buttonHvalueNew;
    }//////////////////////////////////////////////////////////////////////// I //////////////////////////////////////////////////////////////////////////////
    
      if (buttonIvalueNew != buttonIvalueOld){
      if (buttonIvalueNew == LOW){
      MIDI.sendNoteOn(68, 127, 1);
      Serial.println("Note I On");
      }
      else {
      MIDI.sendNoteOff(68, 0, 1);
      Serial.println("Note I Off");
      }
      buttonIvalueOld = buttonIvalueNew;
    }///////////////////////////////////////////////////////////////////// J /////////////////////////////////////////////////////////////////////////////////
    
      if (buttonJvalueNew != buttonJvalueOld){
      if (buttonJvalueNew == LOW){
      MIDI.sendNoteOn(69, 127, 1);
      Serial.println("Note J On");
      }
      else {
      MIDI.sendNoteOff(69, 0, 1);
      Serial.println("Note J Off");
      }
      buttonJvalueOld = buttonJvalueNew;
      }
//////////////////////////////////////////52,54,56,57,59,61,63,64,66,68,69,71,73,75//// K //////////////////////////////////////////////////////////////////////
  if (buttonKvalueNew != buttonKvalueOld){
      if (buttonKvalueNew == LOW){
      MIDI.sendNoteOn(71, 127, 1);
      Serial.println("Note K On");
      }
      
      else {
      MIDI.sendNoteOff(71, 0, 1);
      Serial.println("Note K Off");
      }
      buttonKvalueOld = buttonKvalueNew;
  }/////////////////////////////////////////////////////////////////////// Z ////////////////////////////////////////////////////////////////////////////////////
      
     
  

/////////////////////////////////////////////////////-POTARDS-/////////////////////////////////////////////////////////////////////////////////////////////

int pot1 = analogRead(A0);
int pot2 = analogRead(A1);
int pot3 = analogRead(A2); //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int pot4 = analogRead(A3); //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int pot5 = analogRead(A4); //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
int pot6 = analogRead(A5); //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°


int analogpot1New = analogRead(A0);
int analogpot2New = analogRead(A1);
int analogpot3New = analogRead(A2); //°°°°°°°°°°°°°°°°°°°°
int analogpot4New = analogRead(A3); //°°°°°°°°°°°°°°°°°°°°
int analogpot5New = analogRead(A4); //°°°°°°°°°°°°°°°°°°°°
int analogpot6New = analogRead(A5); //°°°°°°°°°°°°°°°°°°°°

    if (analogpot1New - analogpot1Old >= 35 || analogpot1Old - analogpot1New >= 35) {//////////////////////// POTARD 1 ////////////////////////////////////////
      analogpot1Old = analogpot1New;
      analogpot1New = (map(analogpot1New, 1023, 0, 0, 120));
      analogpot1New = (constrain(analogpot1New, 0, 120));
      MIDI.sendControlChange(analogpot1CC, analogpot1New, 1);
//      Serial.print ("pot: ");
//      Serial.println(pot1);
//      Serial.print("potread: ");
//      Serial.println(analogpot1New); 
    }
    
    if (analogpot2New - analogpot2Old >= 35 || analogpot2Old - analogpot2New >= 35) {////////////////////// POTARD 2 /////////////////////////////////////////
      analogpot2Old = analogpot2New;
      analogpot2New = (map(analogpot2New, 1023, 0, 0, 120));
      analogpot2New = (constrain(analogpot2New, 0, 120));
      MIDI.sendControlChange(analogpot2CC, analogpot2New, 1);
    }
    //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
    if (analogpot3New - analogpot3Old >= 35 || analogpot3Old - analogpot3New >= 35) {////////////////////// POTARD 3 /////////////////////////////////////////
      analogpot3Old = analogpot3New;
      analogpot3New = (map(analogpot3New, 1023, 0, 0, 120));
      analogpot3New = (constrain(analogpot3New, 0, 120));
      MIDI.sendControlChange(analogpot3CC, analogpot3New, 1);
    }
        //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
    if (analogpot4New - analogpot4Old >= 35 || analogpot4Old - analogpot4New >= 35) {////////////////////// POTARD 4 /////////////////////////////////////////
      analogpot4Old = analogpot4New;
      analogpot4New = (map(analogpot4New, 1023, 0, 0, 120));
      analogpot4New = (constrain(analogpot4New, 0, 120));
      MIDI.sendControlChange(analogpot4CC, analogpot4New, 1);
    }
            //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
    if (analogpot5New - analogpot5Old >= 35 || analogpot5Old - analogpot5New >= 35) {////////////////////// POTARD 5 /////////////////////////////////////////
      analogpot5Old = analogpot5New;
      analogpot5New = (map(analogpot5New, 1023, 0, 0, 120));
      analogpot5New = (constrain(analogpot5New, 0, 120));
      MIDI.sendControlChange(analogpot5CC, analogpot5New, 1);
    }
            //°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
    if (analogpot6New - analogpot6Old >= 35 || analogpot6Old - analogpot6New >= 35) {////////////////////// POTARD 6 /////////////////////////////////////////
      analogpot6Old = analogpot6New;
      analogpot6New = (map(analogpot6New, 1023, 0, 0, 120));
      analogpot6New = (constrain(analogpot6New, 0, 120));
      MIDI.sendControlChange(analogpot6CC, analogpot6New, 1);
    }
//      Serial.print ("pot: ");
//      Serial.println(pot2);
//      Serial.print("potread: ");
//      Serial.println(analogpot2New); 
    

delay(25);
}
