/**************Gesamt-Strip-Funktionen**************************/
int Visualize_seven_spectrum_bereiche() //fertig
{
  static int bright[7];
  
 //Nutzt für die Visualisierung alle LEDs
  for (i = 0; i < 7; i++)
  {
    bright[i] = Frequencies_One[i] / 1023. * scale_br;
  }

  fill_solid(&leds[ANFANG_TURM1],     ENDE_TURM1-ANFANG_TURM1+1,        CHSV(led_hue[6], 255, bright[0]));
  fill_solid(&leds[ANFANG_STRASSE1],  ENDE_STRASSE1-ANFANG_STRASSE1+1,  CHSV(led_hue[5], 255, bright[1]));
  fill_solid(&leds[ANFANG_TURM2],     ENDE_TURM2-ANFANG_TURM2+1,        CHSV(led_hue[4], 255, bright[2]));
  fill_solid(&leds[ANFANG_STRASSE2],  ENDE_STRASSE2-ANFANG_STRASSE2+1,  CHSV(led_hue[3], 255, bright[3]));
  fill_solid(&leds[ANFANG_TURM3],     ENDE_TURM3-ANFANG_TURM3+1,        CHSV(led_hue[2], 255, bright[4]));
  fill_solid(&leds[ANFANG_TURM4],     T4B2_ENDE-ANFANG_TURM4+1,         CHSV(led_hue[1], 255, bright[5]));
  fill_solid(&leds[T4B3_ANFANG],      T4B8_ENDE-T4B3_ANFANG+1,          CHSV(led_hue[0], 255, bright[6]));
  return 0;
}
    
