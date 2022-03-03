void loop() {
  // put your main code here, to run repeatedly:

  unsigned long musik_aus, musik_an;  // Zeitpunkte, seit denen die Musik an bzw aus war
  unsigned int wartezeit = 11000;   // ms, bis die Animation umschaltet
  boolean signal_erfasst; // true, wenn gerade ein Signal vorliegt
  static unsigned long debugtimer = 0;
  
  Read_Frequencies();

  // Wurde irgendein Signal detektiert?
  signal_erfasst = false;
  for(int i = 0; i < 7; i++)//gucken, ob die Stadt oder die Visualisation angezeigt wird
  {
    if(Frequencies_One[i] > 150)
    //if(Frequencies_One[i] >= 0)
    {
      signal_erfasst = true;
    }
  }

  // Musik eine Weile aus?
  if (signal_erfasst) {  // gerade Musik an
    musik_an = millis(); // Zeitpunkt merken, als die Musik noch an war
    if (millis() > musik_aus + wartezeit)  // prüfen, wie lange Musik schon an ist
    {
      if(visualisation == false)
      {
         visualisation = true;
         g_erster_aufruf = true;
      }
    }
     
  }
  else  // gerade keine Musik an
  {
    musik_aus = millis();  // Zeitpunkt merken, als die Musik zuletzt aus war
    if (millis() > musik_an + wartezeit)  // prüfen, wie lange Musik schon aus ist
    {
      if(visualisation == true)
      {
        visualisation = false;  // zu lange, Visualisierung abschalten
        g_erster_aufruf = true;

      }
    }
  }

/*
  // DEBUG: auf Musik an setzen !!!
  visualisation = true;
  
  if (millis() > debugtimer + wartezeit || debugtimer == 0) {
    g_erster_aufruf = true;
    debugtimer = millis();
  }
*/

  mainLoop();
}
