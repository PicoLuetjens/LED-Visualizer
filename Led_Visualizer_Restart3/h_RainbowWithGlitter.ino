/**************Gesamt-Strip-Funktionen**************************/
int RainbowWithGlitter()
{
  if (DEBUG>0) Serial.println( "-- RainbowWithGlitter");

  int freq_min = 200;    // minimale Lautstärke für Sparkles

  int j;

  // erst mal alles auf rainbow setzen
  //fill_rainbow(leds, NUM_LEDS, CRGB::Red, deltahue);
  fill_rainbow(leds, NUM_LEDS, initialhue, deltahue);
  // bis zu 11 LEDs auf weiß setzen
  // je lauter der Sound, desto mehr
  for (i=freq_min ; i < Frequencies_One[0] ; i+=1)  // je kleiner die letzte Zahl (step), desto mehr "sparkles" leuchten auf
  // Anzahl sparkles = (1023-freq_min)/step (i+=step)
  {
    j = random (NUM_LEDS);
    leds[j] = CRGB::White;
    //fill_solid(&leds[j], 1, CRGB::White);
  }
  return 0;
}
