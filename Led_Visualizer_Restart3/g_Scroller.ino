/**************Gesamt-Strip-Funktionen**************************/
//#include <FastLED.h>
//FASTLED_USING_NAMESPACE

int Scroller()
{
  if (DEBUG>0) Serial.println( "-- Scroller");

  /*
  {
    for (i = 0; i < 7; i++)
    {
      value = Frequencies_One[i];///1023;
    }
  }
  */
  //Devon Crawford's Code
  
  /**
   * LED Music Visualizer
   * by Devon Crawford
   * using the FastLED library: http://fastled.io/
   * April 22, 2018
   * Watch the video: https://youtu.be/lU1GVVU9gLU
   */
  
  #define updateLEDS 2        // How many do you want to update every millisecond?
  #define COLOR_SHIFT 180000  // Time for colours to shift to a new spectrum (in ms)
  
  // Don't touch these, internal color variation variables
  unsigned long setTime = COLOR_SHIFT;
  int shiftC = 0;
  int mulC = 2;

  unsigned long mytime = millis();
  
  // Shift the color spectrum by 200 on set intervals (setTime)
  if(mytime > setTime) {
    setTime = mytime + COLOR_SHIFT;
    //Serial.println(setTime);
    shiftC += 200;
    mulC++;
    if(shiftC >= 600) {
      shiftC = 0;
    }
    if(mulC > 3) {
      mulC = 2;
    }
  }
  
  // Shift all LEDs to the right by updateLEDS number each time
  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--) {
    leds[i] = leds[i - updateLEDS];
  }
  
  // Get the pitch and brightness to compute the new color
  int newPitch = /*max_input*/ Frequencies_One[0] + shiftC;
  CRGB nc;

  if(newPitch >= 100 && newPitch <= 200) {
    nc.setRGB( 255, 0, 0);
  }
  else if(newPitch >= 200 && newPitch <= 300) {
    int b = (newPitch - 40) * (255/37.0000);
    nc.setRGB( 255, 0, b);
  }
  else if(newPitch > 300 && newPitch <= 400) {
    int r = 255 - ((newPitch - 78) * 2);
    nc.setRGB( r, 0, 255);
  }
  else if(newPitch >= 400 && newPitch <= 500) {
    int g = (newPitch - 206) * (255/32.0000);
    nc.setRGB( 0, g, 255);
  }
  else if(newPitch <= 500 && newPitch <= 600) {
    int r = (newPitch - 239) * (255/11.0000);
    nc.setRGB( r, 255, 255);
  }
  else if(newPitch >= 600 && newPitch <= 700) {
    nc.setRGB(255, 255, 255);
  }
  else if(newPitch >= 700 && newPitch <= 800) {
    int rb = 255-((newPitch-271)*2);
    nc.setRGB(rb, 255, rb);
  }
  else if(newPitch >= 800 && newPitch <= 900) {
    nc.setRGB(0, 255-(newPitch-398), (newPitch-398));
  }
  else {
    nc.setRGB(0, 0, 0);
  }

  // auf erlaubte max. Helligkeit normieren
  nc.setRGB(nc.r * BRIGHTNESS/255., nc.g * BRIGHTNESS/255., nc.b * BRIGHTNESS/255.);


  // Set the left most updateLEDs with the new color
  for(int i = 0; i < updateLEDS; i++) {
    leds[i] = nc;
  }

  //printColor(nc);
  return 0;
}

/**
 * Converts the analog brightness reading into a percentage
 * 100% brightness is 614.. about 3 volts based on frequency to voltage converter circuit
 * The resulting percentage can simply be multiplied on the rgb values when setting our colors,
 * for example black is (0,0,0) so when volume is off we get 0v and all colors are black (leds are off)
 */

double convBrightness(int b) {
  double c = b / 614.0000;
  if( c < 0.2 ) {
    c = 0;
  }
  else if(c > 1) {
    c = 1.00;
  }
  return c;
}

/**
 * Creates a new color from pitch and brightness readings
 * int p         analogRead(pitch) representing the voltage between 0 and 5 volts
 * double b      analogRead(brightness) representing volume of music for LED brightness
 * returns Color structure with rgb values, which appear synced to the music
 */




// Prints color structure data
/*
void printColor(myColor c) {
  Serial.print("( ");
  Serial.print(c.r);
  Serial.print(", ");
  Serial.print(c.g);
  Serial.print(", ");
  Serial.print(c.b);
  Serial.println(" )");
}
*/
