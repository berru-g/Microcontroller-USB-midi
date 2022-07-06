/* MIDI CONTROLLER 
 *  programme AUX MEMES VALEURS QUE "encore un teste midi" 
 *  mais les notes ne sont pas défini, cela permet de mapper les drums :)
 *  structure par
http://www.musiconerd.com
Pimpage Berru 2020 < objectif, CLAVIER et PAD MIDI réunie! 
RESTE A FAIRE:

*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

/////////////////////////////////////////////DECLARATION BUTTON

const int NButtons = 12; // nombre d'entrée
const int button[NButtons] = {2,3,4,5,6,7,8,9,10,11,12,13}; 
int buttonCState[NButtons] = {0}; 
int buttonPState[NButtons] = {0}; 
//sizeof(tableau)/sizeof(tableau[0])
/////////////////////////////////////////////DECLARATION POTARS

const int NPots = 6; //   
const int pot[NPots] = {A0,A1,A2,A3,A4,A5};    
int potCState[NPots] = {0}; // etas actuelle des PIN ANALOGIQUE
int potPState[NPots] = {0}; //etas precedent du portail
int potVar = 0; // valeur entre les etas ? (code source de base

/////////////////////////////////////////////

byte midiCh = 9; // *Canal midi
byte note = 36; //36 DE BASE||| *Note plus grave  utilisée | pour gamme chromatique sinon recréer clavier sans bémol comme ci dessous
//36 EST LA VALEUR DE DEPART DE CHAQUE KIT DRUMS [36 = CASE 1 DU PAD]
//byte notes[NButtons] = {52,54,56,57,59,61,63,64,66,68,69,71,73,75,76}; 
byte cc = 1; 


/////////////////////////////////////////////

int TIMEOUT = 300; //durée pendant laquelle le potentiomètre sera lu après avoir passé le varThreshold
int varThreshold = 4; //seuil de variation du signal du potentiomètre
boolean potMoving = true; // si le potentiomètre bouge
unsigned long pTime[NPots] = {0}; // temps précédemment enregistré
unsigned long timer[NPots] = {0}; // mémoriser le temps écoulé depuis la réinitialisation de la minuterie
/*//processing = visuel
 * unsigned long previousMillis;
unsigned long interval = 20;
 */
/////////////////////////////////////////////

void setup () {

  // midi connection
  MIDI.begin();
  
  Serial.begin(115200);//processing= Serial.begin(57600);
// DIGITAL PIN
  for (int i=0; i<NButtons; i++){
    pinMode(button[i], INPUT_PULLUP);
  }
  
  // ANALOG PIN
  for (int i=0; i<NPots; i++){
    pinMode(pot[i], INPUT_PULLUP);// AJOUT DE PULLUP CAR PAS DE RESISTANCE AVOIR SI CA TIENT§,?!
  }
  

}

void loop () {
/*///processing= visuel
 *         if ( millis() - previousMillis >= 20 ) {
                previousMillis = millis();

                // Lire la valeur du potentiometre.
                int valeur = analogRead(0);

                // Envoyer la valeur du potentiometre.
                Serial.print("A0 "); // en-tete (A0) suivi d'un espace
                Serial.print(valeur); // la valeur
                Serial.println(); // indicateur de fin de ligne             

        }
}
 */
  //DIGITAL PIN
  for (int i=0; i<NButtons; i++) {
    buttonCState[i] = digitalRead(button[i]);
  }
 // buttonCState[2] = !buttonCState[2]; // inversement du port en pullup pulldown!

  //Lire l'état des boutons et envoyez les notes pour chaque boutton actif
  for (int i=0; i<NButtons; i++) {

    if (buttonCState[i] != buttonPState[i]) {

      if(buttonCState[i] == LOW) {     
        MIDI.sendNoteOn(note+i, 127, midiCh); 
        // MIDI.sendNoteOn(note[i], 127, midiCh); // en cas de switch sur le "encore un code midi" pour définir chaque notes?
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

    /*
    Un seuil doit être défini (varThreshold), une valeur minimale que les portes doivent être déplacées
    pour que la lecture commence. Après cela, il est créé comme une sorte de "porte", une porte qui s'ouvre et permet
   que les ports analogiques sont arrêtés sans interruption pendant un certain temps (TIMEOUT). Lorsque la minuterie est inférieure à TIMEOUT
   cela signifie que le potentiomètre a été déplacé pendant une courte période, ce qui signifie qu'il est probablement encore en mouvement,
   il est alors nécessaire de garder le "transporteur" ouvert; dans le cas où le temporisateur est supérieur à TIMEOUT, cela signifie qu'il est déjà temps de le déplacer,
   alors le transporteur doit être fermé. Pour que cette logique se produise, le temporisateur (lignes 99 et 100) doit être remis à zéro chaque fois que la porte analogique
   varient plus que l'ensemble varThreshold.
    */
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
      MIDI.sendControlChange(cc+i, map(potCState[i], 0, 1023, 0, 127), midiCh); 
      potPState[i] = potCState[i]; 
    }
  }
  
}
