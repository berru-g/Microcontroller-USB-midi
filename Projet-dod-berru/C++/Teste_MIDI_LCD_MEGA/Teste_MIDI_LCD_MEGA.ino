//PREMIER TESTE DE CLAVIER MIDI AVEC ECRAN LCD INTEGRé FONCTIONNEL :)
// OBJECTIF, INCLURE MON JEU DE SKATE LORSQU'UN ACCORD PRECIS ET JOUé 
// TOUTE FOIS:
// PROBLEMATIQUE A REGLER
//lcd.print("  GOOD VIBE DUDE "); S'AFFICHE A LA SUITE ET NON PAS LORSQUE JE JOUE UNE NOTE ( A MOINS QUE LE MIDI JOUE SEUL?
// AUSSI
// NOTE A MOI MEME, CECI EST UN EXERCICE DE STYLE POUR S'ENTRAINER, CEST BIEN BERRU TA REUSSI DU PRMIER COUP 
//MAIS Y A AUCUN INTERET A AVOIR UN ECRAN LCD SUR UNE MACHINE USB MIDI, NOTAMENT SI AUCUN MENU!!! 

// DEUXIEME NOTE A MOI MEME, TU TROUVE CA NORMAL DE TE FAIRE DES NOTES A TOI MEME? MOI JE DIS VAS TE COUCHER EN FAIT.
//NUIT DU 8 AU 9 AVRIL 2020
//12 AVRIL: AJOUT DE LA NES = 2 PIN DIGITAL + 1 POTARD

#include <LiquidCrystal.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
const int RS = 2, EN = 3, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);             // 4-bit 
//LiquidCrystal lcd(RS,EN,D1,D2,D3,D4,D5,D6,D7);  // 8-bit 


/////////////////////////////////////////////DECLARATION BUTTON

const int NButtons = 16; // nombre d'entrée plus de 13 déconne, were is the fucking probleme | tirage de cheveux n 457 bordel
const int button[NButtons] = {22,24,26,28,30,32,34,36,38,40,42,44,46, 48,50};
int buttonCState[NButtons] = {0}; 
int buttonPState[NButtons] = {0}; 

/////////////////////////////////////////////DECLARATION POTARS

const int NPots = 9; 
const int pot[NPots] = {A0,A1,A2,A3,A4,A5,A6,A7,A8}; //{A0,A1,A2,A3,A4,A5};
int potCState[NPots] = {0}; // etas actuelle des PIN ANALOGIQUE
int potPState[NPots] = {0}; //etas precedent du portail
int potVar = 0; // valeur entre les etas ? (code source de base

/////////////////////////////////////////////

byte midiCh = 9; // *Canal midi
byte note = 36; //36 DE BASE||| *Note plus grave  utilisée | pour gamme chromatique sinon recréer clavier sans bémol comme ci dessous
//36 EST LA VALEUR DE DEPART DE CHAQUE KIT DRUMS [36 = CASE 1 DU PAD]
//byte notes[NButtons] = {52,54,56,57,59,61,63,64,66,68,69,71, 73, 75, 76, 77}; 
byte cc = 1; 

/////////////////////////////////////////////

int TIMEOUT = 300; //durée pendant laquelle le potentiomètre sera lu après avoir passé le varThreshold
int varThreshold = 4; //seuil de variation du signal du potentiomètre
boolean potMoving = true; // si le potentiomètre bouge
unsigned long pTime[NPots] = {0}; // temps précédemment enregistré
unsigned long timer[NPots] = {0}; // mémoriser le temps écoulé depuis la réinitialisation de la minuterie

/////////////////////////////////////////////
////////////////////////////PIANO/////////////////////////////////////////////////////////////////////////
byte thumbsup1[8] = {
    B11100,
    B11100,
    B11100,
    B11100,
    B11111,
    B11111,
    B11111,
    B11111};
byte thumbsup2[8] = {
    B00100,
    B00100,
    B00100,
    B00100,
    B11111,
    B11111,
    B11111,
    B11111};
byte thumbsup3[8] = {
    B00111,
    B00111,
    B00111,
    B00111,
    B11111,
    B11111,
    B11111,
    B11111};
byte thumbsup4[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  lcd.begin(16,2);       
MIDI.begin();
  
  Serial.begin(115200);
  
    lcd.setCursor(0,0);
  lcd.print(" BERRU  FACTORY"); 
lcd.setCursor(4,1);
lcd.print("USB-MIDI");
  delay(3000);                         
  lcd.clear();                        

lcd.print("CHARGEMENT..."); 
  lcd.createChar(1, thumbsup1);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(3, thumbsup3);
  lcd.createChar(4, thumbsup4);
  lcd.createChar(1, thumbsup1);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(3, thumbsup3);
  lcd.createChar(4, thumbsup4);
  lcd.createChar(1, thumbsup1);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(3, thumbsup3);
  lcd.createChar(4, thumbsup4);
  lcd.createChar(1, thumbsup1);
  lcd.createChar(3, thumbsup3);
///MISE EN PAGE//// 
  lcd.setCursor(0,1);
  lcd.write(1);
    lcd.setCursor(1,1);
  lcd.write(2);
    lcd.setCursor(2,1);
  lcd.write(2);
    lcd.setCursor(3,1);
  lcd.write(3);
    lcd.setCursor(4,1);
  lcd.write(4);
    lcd.setCursor(5,1);
  lcd.write(1);
    lcd.setCursor(6,1);
  lcd.write(2);
    lcd.setCursor(7,1);
  lcd.write(2);
    lcd.setCursor(8,1);
  lcd.write(2);
    lcd.setCursor(9,1);
  lcd.write(3);
    lcd.setCursor(10,1);
  lcd.write(4);
      lcd.setCursor(11,1);
  lcd.write(1);
    lcd.setCursor(12,1);
  lcd.write(2);
    lcd.setCursor(13,1);
  lcd.write(2);
    lcd.setCursor(14,1);
  lcd.write(3);
    lcd.setCursor(15,1);
  lcd.write(4);
delay(2000);
lcd.clear();
////////////////////////////////////////////////////////////////////////////////////

  for (int i=0; i<NButtons; i++){
    pinMode(button[i], INPUT_PULLUP);
  }
  
  // Analog Pin
  for (int i=0; i<NPots; i++){
    pinMode(pot[i], INPUT_PULLUP);
  }
}

void loop() {
 
  for (int i=0; i<NButtons; i++) {
    buttonCState[i] = digitalRead(button[i]);
  }
  buttonCState[2] = !buttonCState[2]; 

  //Lire l'état des boutons et envoyez les notes pour chaque boutton actif
  for (int i=0; i<NButtons; i++) {

    if (buttonCState[i] != buttonPState[i]) {

      if(buttonCState[i] == LOW) {     
        MIDI.sendNoteOn(note+i, 127, midiCh); 
        // MIDI.sendNoteOn(note[i], 127, midiCh); // en cas de switch sur le "encore un code midi" pour définir chaque notes
        buttonPState[i] = buttonCState[i];
      }
      else {
        MIDI.sendNoteOn(note+i, 0, midiCh); 
        // MIDI.sendNoteOn(note[i], 0, midiCh); // faire le teste mais risque de perdre les drums!
        buttonPState[i] = buttonCState[i];
       
      }
    }
    
  }

  ////////////////////////////////////////////////////////////////////////////////////////

  for (int i=0; i<NPots; i++) { // lire les PIN Analog
    potCState[i] = analogRead(pot[i]);
  }

  for (int i=0; i<NPots; i++) {

    potVar = abs(potCState[i] - potPState[i]); // calcul la variation des pin analog

    if (potVar >= varThreshold) {  //définit un seuil pour la variance de l'état du pot, s'il varie plus de x, il envoie le message cc
      pTime[i] = millis(); 
    }
    timer[i] = millis() - pTime[i]; // reset
    if (timer[i] < TIMEOUT) { 
//si la minuterie est inférieure à la durée maximale autorisée, le potentiomètre est toujours en mouvement
      potMoving = true;
    }
    else {
      potMoving = false;
    }

    if (potMoving == true) { //garde le control si  change de valeur
      MIDI.sendControlChange(cc+i, map(potCState[i], 0, 1023, 0, 127), midiCh); // POTARD DECLARE EN CC+I |VERIFIER QUIL NE FAILLE PAS LE METTRE EN CC+(', CC+55 ETC POUR QU4 ABLETON RECONNAISSE LES POT4S INDIVIDUELLEMENT
      potPState[i] = potCState[i]; 
    }
  }
  lcd.print("Serial");
  Serial.printIn();
}
/*
 *   lcd.cursor();                         //CURSEUR
  delay(500);
  lcd.noCursor();                       //C OFF
  delay(500);
  lcd.cursor();                         //CURSEUR
  delay(500);
  lcd.noCursor();                       //C OFF
  delay(500);

 lcd.print("ABLETON LIVE ");
  delay(2000);
  lcd.scrollDisplayLeft();             //MOUVEMENT GAUCHE
  delay(2000);
  

lcd.print("MIDI  CONTROLLER"); 
  lcd.createChar(1, thumbsup1);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(3, thumbsup3);
  lcd.createChar(4, thumbsup4);
  lcd.createChar(1, thumbsup1);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(3, thumbsup3);
  lcd.createChar(4, thumbsup4);
  lcd.createChar(1, thumbsup1);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(2, thumbsup2);
  lcd.createChar(3, thumbsup3);
  lcd.createChar(4, thumbsup4);
  lcd.createChar(1, thumbsup1);
  lcd.createChar(3, thumbsup3);
///MISE EN PAGE//// 
  lcd.setCursor(0,1);
  lcd.write(1);
    lcd.setCursor(1,1);
  lcd.write(2);
    lcd.setCursor(2,1);
  lcd.write(2);
    lcd.setCursor(3,1);
  lcd.write(3);
    lcd.setCursor(4,1);
  lcd.write(4);
    lcd.setCursor(5,1);
  lcd.write(1);
    lcd.setCursor(6,1);
  lcd.write(2);
    lcd.setCursor(7,1);
  lcd.write(2);
    lcd.setCursor(8,1);
  lcd.write(2);
    lcd.setCursor(9,1);
  lcd.write(3);
    lcd.setCursor(10,1);
  lcd.write(4);
      lcd.setCursor(11,1);
  lcd.write(1);
    lcd.setCursor(12,1);
  lcd.write(2);
    lcd.setCursor(13,1);
  lcd.write(2);
    lcd.setCursor(14,1);
  lcd.write(3);
    lcd.setCursor(15,1);
  lcd.write(4);
}
 */
