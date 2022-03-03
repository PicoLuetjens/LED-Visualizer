/*******************Individuell-Array-Funktionen*****************/
void RainbowSaeule_FT(int Anfang, int Ende, int Divisor, int Frequenz, int r, int g, int b)  //Vibes Visualizer mit Rainbow//fertig
{
  if (DEBUG>0) Serial.println( "-- RainbowSaeule_FT");
  
  int ergebnis = Frequencies_One[Frequenz]/Divisor;
  if(ergebnis >=  Ende-Anfang + 1)
  {
    ergebnis = Ende - Anfang + 1;
  }

    //fill_solid(&leds[Anfang], Ende-Anfang + 1, CRGB::Black);//ganzes Array auf Schwarz 
    fadeToBlackBy(&leds[Anfang], Ende-Anfang+1, 90);
    fill_rainbow(&leds[Anfang], ergebnis, CRGB(r, g, b), 10);
   
  
 
}
