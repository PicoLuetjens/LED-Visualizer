int Bereiche_layout1()
{
  if (DEBUG>0) Serial.println( "-- Bereiche_layout1");

  
  // erstes Setup für alle Bereiche(Säulen bei den Türmen) // LAYOUT 1
         //Funktion für Bereich 1
         FrequenzSaeule_FT(ANFANG_TURM1, ENDE_TURM1, 10, 0, random_rgb_values[3], random_rgb_values[4], random_rgb_values[5]);
         
         //Funktion für Bereich 2
         for(int i = ANFANG_STRASSE1; i <= ENDE_STRASSE1; i++)
         {
          leds[i] = CRGB::Black;
         }
         
         //Funktion für Bereich 3
         FrequenzSaeule_FT(ANFANG_TURM2, ENDE_TURM2, 10, 1, random_rgb_values[6], random_rgb_values[7], random_rgb_values[8]);
         
         //Funktion für Bereich 4
          for(int i = ANFANG_STRASSE2; i <= ENDE_STRASSE2; i++)
         {
          leds[i] = CRGB::Black;
         }
         
         //Funktion für Bereich 5
         FrequenzSaeule_FT(ANFANG_TURM3, ENDE_TURM3, 10, 2, random_rgb_values[9], random_rgb_values[10], random_rgb_values[11]);
         
         //Funktion für Bereich 6(restlichen 4 Frequenzen auf jeweils einer Seite von 4 des Turms)
         FrequenzSaeuleVierBalken_FGT(T4B1_ANFANG, T4B1_ENDE, T4B2_ANFANG, T4B2_ENDE, 80, 3, random_rgb_values[0],  random_rgb_values[2], random_rgb_values[4]);//Seite 1
         FrequenzSaeuleVierBalken_FGT(T4B3_ANFANG, T4B3_ENDE, T4B4_ANFANG, T4B4_ENDE, 80, 4, random_rgb_values[1],  random_rgb_values[3], random_rgb_values[5]);//Seite 2
         FrequenzSaeuleVierBalken_FGT(T4B5_ANFANG, T4B5_ENDE, T4B6_ANFANG, T4B6_ENDE, 80, 5, random_rgb_values[6], random_rgb_values[8], random_rgb_values[10]);//Seite 3
         FrequenzSaeuleVierBalken_FGT(T4B7_ANFANG, T4B7_ENDE, T4B8_ANFANG, T4B8_ENDE, 80, 6, random_rgb_values[7],  random_rgb_values[9], random_rgb_values[11]);//Seite 4
         
         //DEBUG
         if (DEBUG>2) Serial.print(random_rgb_values[2]);
         return 0;
}


int Bereiche_layout2()
{
  // zweites Setup für alle Bereiche(RainbowSäulen bei den Türmen) //LAYOUT 2
         //Funktion für Bereich 1
         RainbowSaeule_FT(ANFANG_TURM1, ENDE_TURM1, 10, 0, random_rgb_values[0], random_rgb_values[3], random_rgb_values[6]);
         
         //Funktion für Bereich 2
         for(int i = ANFANG_STRASSE1; i <= ENDE_STRASSE1; i++)
         {
          leds[i] = CRGB::Black;
         }
         
         //Funktion für Bereich 3
         RainbowSaeule_FT(ANFANG_TURM2, ENDE_TURM2, 10, 1, random_rgb_values[1], random_rgb_values[4], random_rgb_values[7]);
         
         //Funktion für Bereich 4
         for(int i = ANFANG_STRASSE2; i <= ENDE_STRASSE2; i++)
         {
          leds[i] = CRGB::Black;
         }
         
         //Funktion für Bereich 5
         RainbowSaeule_FT(ANFANG_TURM3, ENDE_TURM3, 10, 2, random_rgb_values[2], random_rgb_values[5], random_rgb_values[8]);
         
         //Funktion für Bereich 6
         FrequenzSaeuleVierBalkenRainbow_FGT(T4B1_ANFANG, T4B1_ENDE, T4B2_ANFANG, T4B2_ENDE, 80, 3, random_rgb_values[2],   random_rgb_values[1],  random_rgb_values[0]);//Seite 1
         FrequenzSaeuleVierBalkenRainbow_FGT(T4B3_ANFANG, T4B3_ENDE, T4B4_ANFANG, T4B4_ENDE, 80, 3, random_rgb_values[5],   random_rgb_values[4],  random_rgb_values[3]);//Seite 2
         FrequenzSaeuleVierBalkenRainbow_FGT(T4B5_ANFANG, T4B5_ENDE, T4B6_ANFANG, T4B6_ENDE, 80, 3, random_rgb_values[8],   random_rgb_values[7],  random_rgb_values[6]);//Seite 3
         FrequenzSaeuleVierBalkenRainbow_FGT(T4B7_ANFANG, T4B7_ENDE, T4B8_ANFANG, T4B8_ENDE, 80, 3, random_rgb_values[11],  random_rgb_values[10], random_rgb_values[9]);//Seite 4
         return 0;
}

int Bereiche_layout3()
{
  // drittes Setup für alle Bereiche //LAYOUT 3
         //Funktion für Bereich 1
         FrequenzSaeule_FT(ANFANG_TURM1, ENDE_TURM1, 10, 0, random_rgb_values[4], random_rgb_values[9], random_rgb_values[2]);
         
         //Funktion für Bereich 2
         for(int i = ANFANG_STRASSE1; i <= ENDE_STRASSE1; i++)
         {
          leds[i] = CRGB::Black;
         }
         
         //Funktion für Bereich 3
         FrequenzSaeule_FT(ANFANG_TURM2, ENDE_TURM2, 10, 1, random_rgb_values[3], random_rgb_values[11], random_rgb_values[1]);
         
         //Funktion für Bereich 4
          for(int i = ANFANG_STRASSE2; i <= ENDE_STRASSE2; i++)
         {
          leds[i] = CRGB::Black;
         }
         
         //Funktion für Bereich 5
         FrequenzSaeule_FT(ANFANG_TURM3, ENDE_TURM3, 10, 2, random_rgb_values[8], random_rgb_values[5], random_rgb_values[7]);
         
         //Funktion für Bereich 6(restlichen 4 Frequenzen auf jeweils einer Ecke von 4 des Turms)
         FrequenzSaeule_FGT_Ecke(T4B1_ANFANG, T4B1_ENDE, T4B2_ANFANG, T4B2_ENDE, 80, 3, 4, random_rgb_values[6],  random_rgb_values[3], random_rgb_values[11], random_rgb_values[8],  random_rgb_values[2], random_rgb_values[7]);//Seite 1
         FrequenzSaeule_FGT_Ecke(T4B3_ANFANG, T4B3_ENDE, T4B4_ANFANG, T4B4_ENDE, 80, 4, 5, random_rgb_values[8],  random_rgb_values[2], random_rgb_values[7],  random_rgb_values[7],  random_rgb_values[1], random_rgb_values[10]);//Seite 2
         FrequenzSaeule_FGT_Ecke(T4B5_ANFANG, T4B5_ENDE, T4B6_ANFANG, T4B6_ENDE, 80, 5, 6, random_rgb_values[7],  random_rgb_values[1], random_rgb_values[10], random_rgb_values[3],  random_rgb_values[7], random_rgb_values[11]);//Seite 3
         FrequenzSaeule_FGT_Ecke(T4B7_ANFANG, T4B7_ENDE, T4B8_ANFANG, T4B8_ENDE, 80, 6, 3, random_rgb_values[3],  random_rgb_values[7], random_rgb_values[11], random_rgb_values[6],  random_rgb_values[3], random_rgb_values[11]);//Seite 4
         return 0;
}

int Bereiche_layout4()
{
  Leuchtschweif_bereich();
  return 0;
}

int Bereiche_layout5()
{
  EVERY_N_MILLISECONDS (150) 
  {
    //Häuser schwarz
     for(int i = ANFANG_TURM1; i <= ENDE_TURM1; i++)
     {
      leds[i] = CRGB::Black;
     }
     
    //strasse_fluss() für die Straßen
    Strasse_fluss(ANFANG_STRASSE1, ENDE_STRASSE1, random_rgb_values[5],  random_rgb_values[1], random_rgb_values[11]);
    
    //Häuser schwarz
     for(int i = ANFANG_TURM2; i <= ENDE_TURM2; i++)
     {
      leds[i] = CRGB::Black;
     }
  
     //strasse_fluss() für die Straßen
     Strasse_fluss2(ANFANG_STRASSE2, ENDE_STRASSE2, random_rgb_values[5],  random_rgb_values[1], random_rgb_values[11]);
  
     //Häuser schwarz
     for(int i = ANFANG_TURM3; i <= ENDE_TURM3; i++)//<= zu Testzwecken, weil immer das Ende nicht geupdated wird...
     {
      leds[i] = CRGB::Black;
     }
  
     //Häuser schwarz
     for(int i = ANFANG_TURM4; i <= ENDE_TURM4; i++)
     {
      leds[i] = CRGB::Black;
     }
  }
  return 0;
}
