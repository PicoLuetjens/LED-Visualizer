/*********************Stadt-Funktionen*********************/
void StadtHaus(int Anfang, int Ende)
{
  if (DEBUG>0) Serial.println( "-- StadtHaus");
  
  if (g_erster_aufruf)
  {
    if (DEBUG>2) Serial.println("----- erster Aufruf. --> alles schwarz.");
    // debug: wieder löschen!
    fill_solid(&(leds[Anfang]), Ende-Anfang+1, CRGB::Green); // alles schwarz
  }

  int x = random(2);  // 0: alles gelb, 1: gelb/schwarz-Muster

  // DEBUG
  // x = 0;
  
  if(x == 0)  // alles gelb
  {
    if (DEBUG>2) Serial.println("----- alles gelb.");
    fill_solid(&(leds[Anfang]), Ende-Anfang+1, CRGB::Yellow);//entweder voll gefüllt mit Licht
  }

  else // gelb/schwarz-Muster
  {
    if (DEBUG>2) Serial.println("----- gelb/schwarz-Muster.");
    for(int i = Anfang; i < Ende; i++)
   {
      int y = random(2);
      if (y == 0)
      {
        if (DEBUG>3) Serial.print( "LED # ");
        if (DEBUG>3) Serial.print(i);
        if (DEBUG>3) Serial.println( ": \tgelb");

        leds[i] = CRGB::Yellow;
      }
      else
      {
        if (DEBUG>3) Serial.print( "LED # ");
        if (DEBUG>3) Serial.print(i);
        if (DEBUG>3) Serial.println( ": \tschwarz");

        leds[i] = CRGB::Black;
      }
    }
  }
  if (DEBUG>2) Serial.println(">>> Ende StadtHaus");
}
