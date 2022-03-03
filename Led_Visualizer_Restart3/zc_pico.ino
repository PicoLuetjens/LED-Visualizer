//***************************LED-WAND-FUNKTION****************************
void Pico()
{
  //PicoPatterns[PicoCurrentPatternNumber] ();
  if (DEBUG>0) Serial.println( "-- Pico");
  switch(PicoCurrentPatternNumber)
  {
    case 0:
      blink_f();
      break;
    case 1:
      P();
      break;
    case 2:
      I();
      break;
    case 3:
      C();
      break;
    case 4:
      O();
      break;
  }
  
  EVERY_N_SECONDS(1)
  {
    nextPattern();
  }
  
}


void P()
{
  int r = Pico_r;
  int g = Pico_g;
  int b = Pico_b;
  
  //leds2[10] = CRGB(r, g, b);
  //leds2[11] = CRGB(r, g, b);
  //leds2[12] = CRGB(r, g, b);
  //leds2[13] = CRGB(r, g, b);
  fill_solid(&leds2[10], 4, CRGB(r, g, b));
  leds2[18] = CRGB(r, g, b);
  leds2[21] = CRGB(r, g, b);
  //leds2[26] = CRGB(r, g, b);
  //leds2[27] = CRGB(r, g, b);
  //leds2[28] = CRGB(r, g, b);
  //leds2[29] = CRGB(r, g, b);
  fill_solid(&leds2[26], 4, CRGB(r, g, b));
  leds2[34] = CRGB(r, g, b);
  leds2[42] = CRGB(r, g, b);
  leds2[50] = CRGB(r, g, b);
}
  
void I()
{
  int r = Pico_r;
  int g = Pico_g;
  int b = Pico_b;

  //leds2[11] = CRGB(r, g, b);
  //leds2[12] = CRGB(r, g, b);
  fill_solid(&leds2[11], 2, CRGB(r, g, b));
  //leds2[27] = CRGB(r, g, b);
  //leds2[28] = CRGB(r, g, b);
  fill_solid(&leds2[27], 2, CRGB(r, g, b));
  //leds2[35] = CRGB(r, g, b);
  //leds2[36] = CRGB(r, g, b);
  fill_solid(&leds2[35], 2, CRGB(r, g, b));
  //leds2[43] = CRGB(r, g, b);
  //leds2[44] = CRGB(r, g, b);
  fill_solid(&leds2[43], 2, CRGB(r, g, b));
  //leds2[51] = CRGB(r, g, b);
  //leds2[52] = CRGB(r, g, b);
  fill_solid(&leds2[51], 2, CRGB(r, g, b));
}

void C()
{
  int r = Pico_r;
  int g = Pico_g;
  int b = Pico_b;

  //leds2[10] = CRGB(r, g, b);
  //leds2[11] = CRGB(r, g, b);
  //leds2[12] = CRGB(r, g, b);
  //leds2[13] = CRGB(r, g, b);
  fill_solid(&leds2[10], 4, CRGB(r, g, b));
  leds2[18] = CRGB(r, g, b);
  leds2[26] = CRGB(r, g, b);
  leds2[34] = CRGB(r, g, b);
  leds2[42] = CRGB(r, g, b);
  //leds2[50] = CRGB(r, g, b);
  //leds2[51] = CRGB(r, g, b);
  //leds2[52] = CRGB(r, g, b);
  //leds2[53] = CRGB(r, g, b);
  fill_solid(&leds2[50], 4, CRGB(r, g, b));
}

void O()
{
  int r = Pico_r;
  int g = Pico_g;
  int b = Pico_b;

  //leds2[10] = CRGB(r, g, b);
  //leds2[11] = CRGB(r, g, b);
  //leds2[12] = CRGB(r, g, b);
  //leds2[13] = CRGB(r, g, b);
  fill_solid(&leds2[10], 4, CRGB(r, g, b));
  leds2[18] = CRGB(r, g, b);
  leds2[21] = CRGB(r, g, b);
  leds2[26] = CRGB(r, g, b);
  leds2[29] = CRGB(r, g, b);
  leds2[34] = CRGB(r, g, b);
  leds2[37] = CRGB(r, g, b);
  leds2[42] = CRGB(r, g, b);
  leds2[45] = CRGB(r, g, b);
  //leds2[50] = CRGB(r, g, b);
  //leds2[51] = CRGB(r, g, b);
  //leds2[52] = CRGB(r, g, b);
  //leds2[53] = CRGB(r, g, b);
  fill_solid(&leds2[50], 4, CRGB(r, g, b));
}

void nextPattern()
{
  fill_solid(leds2, NUM_LEDS2, CRGB(0, 0, 0));
  PicoCurrentPatternNumber = PicoCurrentPatternNumber + 1;
  if(PicoCurrentPatternNumber == 5)
    PicoCurrentPatternNumber = 0;
  // add one to the current pattern number, and wrap around at the end
  //PicoCurrentPatternNumber = (PicoCurrentPatternNumber + 1) % ARRAY_SIZE( PicoPatterns);
}

void blink_f()//blinkt alle 250Ms
{
  int r = Pico_r;
  int g = Pico_g;
  int b = Pico_b;

  fill_solid(leds2, NUM_LEDS2, CRGB(0, 0, 0));
  
  EVERY_N_MILLISECONDS(50)
  {
    fill_solid(leds2, NUM_LEDS2, CRGB(r, g, b));
  }
}
