/*********************Stadt-Funktionen*********************/
//fertig

void Stadt()
{
  if (DEBUG>0) Serial.println( "-- Stadt");

  //Serial.println (last_timer_T1);

  // Straßen visualisieren
  EVERY_N_SECONDS(1)  // jede Sekunde
  {
    StadtStrasse(ANFANG_STRASSE1, ENDE_STRASSE1);
    StadtStrasse(ANFANG_STRASSE2, ENDE_STRASSE2);
  }

  // Türme visualisieren
  EVERY_N_SECONDS(5)  //alle 5 Sekunden
  {
    StadtHaus(ANFANG_TURM1, ENDE_TURM1);
    StadtHaus(ANFANG_TURM2, ENDE_TURM2);
    StadtHaus(ANFANG_TURM3, ENDE_TURM3);
    StadtHaus(ANFANG_TURM4, ENDE_TURM4);
  }
}
