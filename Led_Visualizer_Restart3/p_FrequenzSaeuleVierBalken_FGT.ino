/*******************Individuell-Array-Funktionen*****************/
void FrequenzSaeuleVierBalken_FGT(int Anfang_strip1, int Ende_strip1, int Anfang_strip2, int Ende_strip2, int Divisor, int Frequenz, int r,  int g, int b)//für eine Frequenz an der Seite(1 von 4 Seiten)//fertig
{
  if (DEBUG>0) Serial.println( "-- FrequenzSaeuleVierBalken_FGT");
  
  int ergebnis1 = Frequencies_One[Frequenz]/Divisor;
  if(ergebnis1 >=  Ende_strip1-Anfang_strip1 + 1)
  {
    ergebnis1 = Ende_strip1 - Anfang_strip1 + 1;
  }
  int ergebnis2 = Frequencies_One[Frequenz]/Divisor;
  if(ergebnis2 >=  Ende_strip2-Anfang_strip2 + 1)
  {
    ergebnis2 = Ende_strip2 - Anfang_strip2 + 1;
  }
  //fill_solid(&leds[Anfang_strip1], Ende_strip2-Anfang_strip1 + 1, CRGB::Black);//ganzes Array auf Schwarz 
  fadeToBlackBy(&leds[Anfang_strip1], Ende_strip2-Anfang_strip1 + 1, 90);
  fill_solid(&leds[Anfang_strip1], ergebnis1, CRGB(r, g, b));
  //fadeToBlackBy(&leds[Anfang_strip1], ergebnis1, 40);
  fill_solid(&leds[Ende_strip2-ergebnis2]+1, ergebnis2, CRGB(r, g, b));
  //fadeToBlackBy(&leds[Ende_strip2-ergebnis2]+1, ergebnis2, 40);

}
