/****************Individuell-Array-Funktionen**********************///NOCH NICHT FERTIG!!!!
void Leuchtschweif_bereich()
{
  int fader_wert = 40;
  
  if (DEBUG>0) Serial.println( "-- Leuchtschweif_bereich");

  int pos_bereich1 = map(Frequencies_One[0], 0, 1023, ANFANG_TURM1+1,     ENDE_TURM1-1);
  int pos_bereich2 = map(Frequencies_One[1], 0, 1023, ANFANG_STRASSE1+1,  ENDE_STRASSE1-1);
  int pos_bereich3 = map(Frequencies_One[2], 0, 1023, ANFANG_TURM2+1,     ENDE_TURM2-1);
  int pos_bereich4 = map(Frequencies_One[3], 0, 1023, ANFANG_STRASSE2+1,  ENDE_STRASSE2-1);
  int pos_bereich5 = map(Frequencies_One[4], 0, 1023, ANFANG_TURM3+1,     ENDE_TURM3-1);
  int pos_bereich6 = map(Frequencies_One[5], 0, 1023, ANFANG_TURM4+1,     T4B4_ENDE-1);
  int pos_bereich7 = map(Frequencies_One[6], 0, 1023, T4B5_ANFANG+1,      ENDE_TURM4-1);

  fadeToBlackBy(&leds[ANFANG_TURM1], ENDE_TURM1-ANFANG_TURM1+1, fader_wert);
  leds[pos_bereich1-1]  += CHSV(led_hue[0], 255, 192);  
  leds[pos_bereich1]    += CHSV(led_hue[0], 255, 192);
  leds[pos_bereich1+1]  += CHSV(led_hue[0], 255, 192);
    
  fadeToBlackBy(&leds[ANFANG_STRASSE1], ENDE_STRASSE1-ANFANG_STRASSE1+1, fader_wert);
  leds[pos_bereich2-1] += CHSV(led_hue[1], 255, 192);
  leds[pos_bereich2] += CHSV(led_hue[1], 255, 192);
  leds[pos_bereich2+1] += CHSV(led_hue[1], 255, 192);

  fadeToBlackBy(&leds[ANFANG_TURM2], ENDE_TURM2-ANFANG_TURM2+1, fader_wert);
  leds[pos_bereich3-1] += CHSV(led_hue[2], 255, 192);
  leds[pos_bereich3] += CHSV(led_hue[2], 255, 192);
  leds[pos_bereich3+1] += CHSV(led_hue[2], 255, 192);

  fadeToBlackBy(&leds[ANFANG_STRASSE2], ENDE_STRASSE2-ANFANG_STRASSE2+1, fader_wert);
  leds[pos_bereich4-1] += CHSV(led_hue[3], 255, 192);
  leds[pos_bereich4] += CHSV(led_hue[3], 255, 192);
  leds[pos_bereich4+1] += CHSV(led_hue[3], 255, 192);

  fadeToBlackBy(&leds[ANFANG_TURM3], ENDE_TURM3-ANFANG_TURM3+1, fader_wert);
  leds[pos_bereich5-1] += CHSV(led_hue[4], 255, 192);
  leds[pos_bereich5] += CHSV(led_hue[4], 255, 192);
  leds[pos_bereich5+1] += CHSV(led_hue[4], 255, 192);

  fadeToBlackBy(&leds[ANFANG_TURM4], T4B4_ENDE-ANFANG_TURM4+1, fader_wert);
  leds[pos_bereich6-1] += CHSV(led_hue[5], 255, 192);
  leds[pos_bereich6] += CHSV(led_hue[5], 255, 192);
  leds[pos_bereich6+1] += CHSV(led_hue[5], 255, 192);

  fadeToBlackBy(&leds[T4B5_ANFANG], ENDE_TURM4-T4B5_ANFANG+1, fader_wert);
  leds[pos_bereich7-1] += CHSV(led_hue[6], 255, 192);
  leds[pos_bereich7] += CHSV(led_hue[6], 255, 192);
  leds[pos_bereich7+1] += CHSV(led_hue[6], 255, 192);

  /*
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, fader_wert);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( led_hue[0], 255, 192);
  */
}
