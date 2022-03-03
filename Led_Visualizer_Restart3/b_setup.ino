void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // open the serial port at 9600 bps:
  Serial.println("**************************************************");
  Serial.println("***************** S T A R T **********************");
  Serial.println("**************************************************");

  delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA_PIN2, COLOR_ORDER>(leds2, NUM_LEDS2).setCorrection(TypicalLEDStrip); //für zweiten Strip(LED-DISPLAY)

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  // einmal alle Farben anmachen
  for (i = 0; i < 7; i++)
    leds[i] = CHSV( led_hue[i], 255, BRIGHTNESS);
  //leds[i].setHue( led_hue[i] );
  FastLED.show();
  delay(3000); // 3 second delay
  for (i = 0; i < 7; i++)
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
  //timer = millis() / 1000;      //Starten des Timers in Sekunden
}

//*********************************************************************************************//Liste LED-ARRAY 1
// List of patterns to cycle through.  Each is defined as a separate function below. 
typedef int (*SimplePatternList[])();
SimplePatternList A1Patterns = { Visualize_seven_spectrum, Visualize_seven_spectrum_bereiche, Scroller, RainbowWithGlitter, juggle, Bereiche_layout1, Bereiche_layout2, Bereiche_layout3, Bereiche_layout4, Bereiche_layout5, Fade_to_white, Fade_to_black, random_wipe, wipe_von_beiden_seiten, pulse_blink, pulse_blink  }; // pulse_blink muss immer ganz hinten stehen!!!

int A1CurrentPatternNumber = 9; // Index number of which pattern is current

//**********************************************************************************************************/Pico-FunktionsListe
// List of patterns to cycle through.  Each is defined as a separate function below.
//typedef void (*SimplePatternList[])();
//PicoPatternList PicoPatterns = { blink_f, P, I, C, O };

int PicoCurrentPatternNumber = 1; // Index number of which pattern is current
