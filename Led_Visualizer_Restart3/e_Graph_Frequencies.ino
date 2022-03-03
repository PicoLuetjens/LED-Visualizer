/***************Light LEDs based on frequencies(TEST-FUNKTION)******************/
void Graph_Frequencies() {
  Serial.print( "val: ");
  for ( i = 0; i < 7; i++)
  {
    bright = Frequencies_One[i] / 1023. * scale_br;
    if (bright > BRIGHTNESS)
      bright = BRIGHTNESS;

    leds[i] = CHSV( led_hue[i], 255, bright );
    Serial.print( bright );
    Serial.print( "\t");
  }
  Serial.println ("");
  FastLED.show();
}
