/*************Pull frquencies from Spectrum Shield****************/
void Read_Frequencies() {
  //if (DEBUG>0) Serial.println( "-- Read_Frequencies");

  int i;

  max_input = 0;
  //Read frequencies for each band
  for (i=0; i<7; i++)
  {
    Frequencies_One[i] = analogRead(DC_One);  // Wert auslesen
    if (Frequencies_One[i] > max_input)        // max. Wert bestimmen
      max_input = Frequencies_One[i];
    Frequencies_Two[i] = analogRead(DC_Two);  // Wert auslesen
    if (Frequencies_Two[i] > max_input)        // max. Wert bestimmen
      max_input = Frequencies_Two[i];

    // Nächsten Wert abfragen
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }

  /*
  for (freq_amp = 0; freq_amp < 7; freq_amp++)
  {
    Serial.print (Frequencies_One[freq_amp]);
    Serial.print ("\t");
  }
  Serial.println ("");
  */
}
