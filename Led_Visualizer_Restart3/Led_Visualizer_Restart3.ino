#define DEBUG 0

// -------------------- fastLED einrichten --------------------
#include <FastLED.h>
FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    6
//#define CLK_PIN   4
#define DATA_PIN2   7 //für zweiten Strip(LED-DISPLAY)
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB 
#define NUM_LEDS    530 //gesamtes LED-Array-Anzahl
#define NUM_LEDS2   64  //für zweiten Strip(LED-DISPLAY)
#define ANFANG_TURM1  0  //einzelne Bereich-LED-Arrays Anzahlen
#define ENDE_TURM1  117
#define ANFANG_STRASSE1  118
#define ENDE_STRASSE1  151
#define ANFANG_TURM2  152
#define ENDE_TURM2  271
#define ANFANG_STRASSE2  272
#define ENDE_STRASSE2  298
#define ANFANG_TURM3  299
#define ENDE_TURM3  417
#define ANFANG_TURM4  418
#define ENDE_TURM4  529
#define T4B1_ANFANG 418  //Vier Eck-Bereiche von Turm 4, um sie umgedreht ansteuern zu können(T4B1 == Turm 4 Bereich 1) Anmerkung: wenn interaktiv programmiert dann vllt lieber int nehmen, da es mit #define manchmal probleme gibt...
#define T4B1_ENDE 431
#define T4B2_ANFANG 432
#define T4B2_ENDE 445
#define T4B3_ANFANG 446
#define T4B3_ENDE 459
#define T4B4_ANFANG 460
#define T4B4_ENDE 473
#define T4B5_ANFANG 474 
#define T4B5_ENDE 487
#define T4B6_ANFANG 488
#define T4B6_ENDE 501
#define T4B7_ANFANG 502
#define T4B7_ENDE 515
#define T4B8_ANFANG 516
#define T4B8_ENDE 529

// wird für ein Array benutzt
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

unsigned long last_timer_T1;
unsigned long last_timer_T2;
unsigned long last_timer_T3;
unsigned long last_timer_T4;
unsigned long last_timer_S1=15;
unsigned long last_timer_S2;

CRGB leds[NUM_LEDS];  //gesamtes LED-Array
CRGB leds2[NUM_LEDS2]; //für zweiten Strip(LED-DISPLAY)

#define BRIGHTNESS         80
#define FRAMES_PER_SECOND  30

// Skalierungsfaktor
static float scale_br = 256;    // maximale Brightness für die einzelnen Vuisualisierungen; im Regelfall 256;
                                // wird noch durch BRIGHTNESS auf max. Wert gedimmt.
static int bright;             // Zwischenspeicher fuer brightness

//generelle Variablen
static int value;              // Anstelle von bright für andere Nutzung von Werten
static int Animation_counter = 0;  //fürs Zählen der Animationen       
//unsigned long timer;    //timer für einzelne Animationen zum wechseln
boolean beat_heavy = false; //wird in Mainloop verwendet(entscheidet ob eine funktion ausgewählt werden kann, weil diese Beat braucht um zu funktionieren)


static boolean visualisation = false; //Fürs Umschalten zwischen Visualisierung und Stadt
static boolean individuell = false;  //Fürs Umschalten zwischen ganzem Strip und einzelnen Bereichen(in der Visualisierung)
static boolean g_erster_aufruf;    // wird auf true gesetzt, wenn Wechsel zwischen Visualisierung stattfindet
static int random_rgb_values[] = {random8(), random8(), random8(), random8(), random8(), random8(), random8(), random8(), random8(), random8(), random8(), random8()}; //12 Random-Werte zum benutzen für zufällige Farbe
int index = 0;                        //Index für Random-Wipe
int index2 = 0;                       //Indexe für wipe_von_beiden_seiten
int index3 = NUM_LEDS;

//static unsigned int deltahue = 7;
static uint8_t deltahue = 7;
static uint8_t initialhue = 0;

//wird nur in einer Funktion genutzt, muss aber global sein(Beat_Scale)
int erste_farbe = random_rgb_values[6];
int zweite_farbe = random_rgb_values[2];
int dritte_farbe = random_rgb_values[9];
//Info:_FT steht für "Für Türme" und _FS steht für "Für Straße" bei den individuellen Funktionen

//Für strasse-fluss
boolean strasse_fluss_erster_aufruf = true;
boolean strasse_fluss2_erster_aufruf = true;
int fluss[ENDE_STRASSE1-ANFANG_STRASSE1+1];
int fluss2[ENDE_STRASSE2-ANFANG_STRASSE2+1];
boolean cc = true;
boolean cc2 = true;

//Für Pulse_blink
int choose_bereich;
boolean in = false;//wahr wenn der Frequenzwert über Schwellenwert ist 
boolean chosen = false;//wahr wenn wert für einen Bereich random ausgesucht wurde
boolean filled = false; //wahr, wenn ein Bereich für einen Frame gefüllt wurde
int analyse_array[200];
int last_choices[8];
boolean gleich = true;//für Vergleich in mainloop


//Werden noch nicht gebraucht
//Für Tetris(LED-WAND)
int all_pos[64];
int tile_pos[4];
int tile_test[4];
int all_pos_laenge;
boolean blocked = false;

//Für Beat_position_four
boolean position_four_erster_aufruf = true;
boolean schalter = true;

//Für Pico
int Pico_r = random_rgb_values[0];
int Pico_g = random_rgb_values[10];
int Pico_b = random_rgb_values[6];

// -------------------- Spectrum Shield pin connections --------------------
#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1


//Define LED connections on the Arduino/Shield
static int led_hue[] = {0, 35, 70, 105, 140, 175, 210};

//Define spectrum variables
static int max_input;   // maximales Input Signal aus 
static int Frequencies_One[7];
static int Frequencies_Two[7];
int i;

// Deklarationen von Funktionen
void mainLoop();
