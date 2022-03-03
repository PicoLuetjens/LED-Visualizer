/**************Gesamt-Strip-Funktionen**************************/
int pulse_blink()//(nur für "Beat-heavy" Songs)
{
  
  fadeToBlackBy(leds, NUM_LEDS, 80);
  
  if(Frequencies_One[0] > 600)
  {
    in = true;
    filled = false;
  }
  else
  {
    in = false;
    chosen = false;
  }

  if(in&&!chosen)
  {
    choose_bereich = random(1, 7);
    chosen = true;
  }
  if(!filled)
  {
    switch(choose_bereich)
    {
      case 1:
        fill_solid(&leds[ANFANG_TURM1], ENDE_TURM1-ANFANG_TURM1+1, CRGB(random_rgb_values[0], random_rgb_values[1], random_rgb_values[2]));  
        break;
      case 2:
        fill_solid(&leds[ANFANG_STRASSE1], ENDE_STRASSE1-ANFANG_STRASSE1+1, CRGB(random_rgb_values[3], random_rgb_values[4], random_rgb_values[5]));  
        break;
      case 3:
        fill_solid(&leds[ANFANG_TURM2], ENDE_TURM2-ANFANG_TURM2+1, CRGB(random_rgb_values[6], random_rgb_values[7], random_rgb_values[8]));  
        break;
      case 4:
        fill_solid(&leds[ANFANG_STRASSE2], ENDE_STRASSE2-ANFANG_STRASSE2+1, CRGB(random_rgb_values[9], random_rgb_values[10], random_rgb_values[11]));  
        break;
      case 5:
        fill_solid(&leds[ANFANG_TURM3], ENDE_TURM3-ANFANG_TURM3+1, CRGB(random_rgb_values[8], random_rgb_values[4], random_rgb_values[1]));  
        break;
      case 6:
        fill_solid(&leds[ANFANG_TURM4], ENDE_TURM4-ANFANG_TURM4+1, CRGB(random_rgb_values[2], random_rgb_values[1], random_rgb_values[3])); 
        break; 
    }
    filled = true;
  }
  return 0;
}
