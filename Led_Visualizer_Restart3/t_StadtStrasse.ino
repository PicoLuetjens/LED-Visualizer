/*********************Stadt-Funktionen*********************///fertig
void StadtStrasse(int Anfang, int Ende)
{
  if (DEBUG>0) Serial.println( "-- StadtStrasse");
  
  int i;
  boolean neues_auto;
  //int max_car_count = 5;
  //int current_car_count;
  int i_ende = Anfang+random(2,5);

  /* Erster Aufruf? */
  if (g_erster_aufruf) {
    if (DEBUG > 2) Serial.println("Erster Aufruf.");

    // Autos setzen
    fill_solid( &(leds[Anfang]), Ende-Anfang+1, CRGB::Black );  // alles auf schwarz setzen
    i=Anfang;
    do {
      leds[i] = CRGB::Red;
      i += random (2, 5);
    } while (i<=Ende);
  }

  // Autos weiterschieben
  else
  {
    // alle Autos weiter schieben
    i = Ende;
    while (i> Anfang) {
      leds[i] = leds[i-1];
      i--;
    }

    // Neues Auto setzen?
    // suche im Bereich 2 bis 2...5 (Zufall) nach schon vorhandenem Auto, damit die Abstände eingehalten werden
    neues_auto = true;
    for (i=Anfang+1 ; i<i_ende ; i++) {
      if (leds[i].r > 0 || leds[i].g > 0 || leds[i].b > 0)  // Auto gefunden: noch kein neues Auto setzen!
        neues_auto = false;
    }
    if (neues_auto) // kein Auto gefunden? dann neues setzen.
      leds[Anfang] = CRGB::Red;
    else
      leds[Anfang] = CRGB::Black;
  }
}
