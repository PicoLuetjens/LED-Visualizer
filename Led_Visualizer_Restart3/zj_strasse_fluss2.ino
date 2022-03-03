void Strasse_fluss2(int Anfang, int Ende, int r, int g, int b)
{
  if (DEBUG>0) Serial.println( "-- Strasse_fluss2");
  
  //fill_solid(leds, NUM_LEDS, CRGB::Green);

  int richtung; //Richtung, in die die LEDS ziehen sollen
  int anz_LEDs = Ende-Anfang+1;

  if(strasse_fluss2_erster_aufruf)//beim ersten Aufruf das fluss2-Array beschreiben
  {
    if (DEBUG>2) Serial.println( "-- Strasse_fluss: erster Aufruf");
    for(int i = 0; i < anz_LEDs; i++)
    {
      if(i%3 == 0)  fluss2[i] = 1;//Die die leuchten sollen kriegen den Wert 1 zugewiesen, die anderen den Wert 0
      else          fluss2[i] = 0;
    }

    if (DEBUG>3) {
      for (int j=0 ; j<anz_LEDs ; j++){
        Serial.print(fluss2[j]);
        Serial.print(" ");
      }
      Serial.println("");
    }

    strasse_fluss2_erster_aufruf = false;
  }

  
  // Flussrichtung festlegen: normal 0, wenn laut 1
  if(/*max_input*/ Frequencies_One[0] > 400)
  {
    richtung = 1;
  }
  else
  {
    richtung = 0;
  }

  if (DEBUG>2) {
    Serial.print("-- Strasse_fluss2: Richtung = ");
    Serial.println(richtung);
  }

  // wenn sehr laut, Farbe ändern
  if(/*max_input*/ Frequencies_One[0] > 700 && cc2)
  {
    if (DEBUG>2) Serial.println( "-- Strasse_fluss2: LAUT! --> Farbe ändern");
    r = random_rgb_values[10];
    g = random_rgb_values[11];
    b = random_rgb_values[12];
    cc2 = false;
  }

   if(Frequencies_One[0] < 900 && !cc2)
  {
    cc2 = true;
  }

  // ***** Array neu berechnen (schieben) *****
  if(richtung == 1) // nach unten schieben
  {
    for(int i = 0; i < anz_LEDs-1; i++)
      fluss2[i] = fluss2[i+1];
    fluss2[anz_LEDs-1] = fluss2[anz_LEDs-4];
  }
  else            // nach oben schieben
  {
    for(int i = anz_LEDs-1; i > 0; i--)
      fluss2[i] = fluss2[i-1];
    fluss2[0] = fluss2[3];
  }

  // Array ausgeben  
  if (DEBUG>3) {
    for (int j=0 ; j<anz_LEDs ; j++){
      Serial.print(fluss2[j]);
      Serial.print(" ");
    }
    Serial.println("");
  }


  // fluss2 array auf LEDs übertragen
  for(int i = 0; i < anz_LEDs; i++)
  {
    if(fluss2[i] == 1)
    {
      leds[Anfang+i] = CRGB(r, g, b);
    }
    else
    {
      leds[Anfang+i] = CRGB::Black;
    }
  }
}
