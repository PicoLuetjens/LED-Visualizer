// -------------------- fastLED einrichten --------------------
#include <FastLED.h>
FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    6
//#define CLK_PIN   4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    7
CRGB leds[NUM_LEDS];

#define BRIGHTNESS         120
#define FRAMES_PER_SECOND  120

// Skalierungsfaktor
float scale_br=400.0;   // Verstaerkung der Brightness
int bright;             // Zwischenspeicher fuer brightness

// -------------------- Spectrum Shield pin connections --------------------
#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1


//Define LED connections on the Arduino/Shield
int led_hue[] = {0, 35, 70, 105, 140, 175, 210};

//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7];
int i;

/********************Setup Loop*************************/
void setup() {
  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  // einmal alle Farben anmachen
  for (i = 0; i<7; i++)
    leds[i] = CHSV( led_hue[i], 255, BRIGHTNESS);
    //leds[i].setHue( led_hue[i] );
  FastLED.show();
  delay(3000); // 3 second delay
  for (i = 0; i<7; i++)
    leds[i] = CHSV( led_hue[i], 255, 0);
  FastLED.show();

  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);
  digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);

  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);
  delay(1);
  digitalWrite(STROBE, HIGH);
  delay(1);
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, LOW);

  Serial.begin( 9600 );
}

/****************Main Function Loop***************************/
void loop() {

  Read_Frequencies();
  Graph_Frequencies();
  delay(50);

}

/*************Pull frquencies from Spectrum Shield****************/
void Read_Frequencies(){
  //Read frequencies for each band
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    Frequencies_One[freq_amp] = analogRead(DC_One);
    Frequencies_Two[freq_amp] = analogRead(DC_Two);
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    Serial.print (Frequencies_One[freq_amp]);
    Serial.print ("\t");
  }
  Serial.println ("");
}

/***************Light LEDs based on frequencies******************/
void Graph_Frequencies(){

  Serial.print( "val: ");
  for( i= 0; i<7; i++)
  {
    bright = Frequencies_One[i]/1023. * scale_br;
    if (bright > BRIGHTNESS)
      bright = BRIGHTNESS;
    leds[i] = CHSV( led_hue[i], 255, bright );

    Serial.print( bright );
    Serial.print( "\t");
  }
  Serial.println ("");
  FastLED.show();
}
