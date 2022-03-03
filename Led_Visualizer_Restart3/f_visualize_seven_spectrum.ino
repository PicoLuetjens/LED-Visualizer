/**************Gesamt-Strip-Funktionen**************************/
int Visualize_seven_spectrum() {
  int anzahl;
  if (DEBUG>0) Serial.println( "-- Visualize_seven_spectrum");

  //Nutzt für die Visualisierung alle LEDs
  for (i = 0; i < 7; i++)
  {
    bright = Frequencies_One[i] / 1023. * scale_br;
    
    if (DEBUG > 2) {
      Serial.print("    Channel: ");
      Serial.print(i);
      Serial.print(" brightness: ");
      Serial.println(bright);
    }

    // Bereichsgrenzen festlegen
    // sieben gleich große Bereiche; der letzte wird ggf. gekappt
    for (int j = 0 ; j < NUM_LEDS / 7; j++)
    {
      if((NUM_LEDS / 7+1)*(i+1) > NUM_LEDS)
      {
        anzahl = NUM_LEDS-(NUM_LEDS / 7+1)*i;
      }
      else
      {
        anzahl = NUM_LEDS / 7+1;
      }

      // Bereich mit Farbe füllen
      fill_solid(&leds[(NUM_LEDS / 7+1)*i], anzahl, CHSV(led_hue[i], 255, bright));
    }
    
  }
  //fill_solid(leds, NUM_LEDS, CRGB::Green);
  //delay(1000);
  return 0;
}
