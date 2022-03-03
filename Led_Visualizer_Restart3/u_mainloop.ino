/***************************Main Schleife*******************/
void newPattern1(int lc[], int von, int bis)
{
  boolean gleich = true;
  while(gleich)
  {
    if (DEBUG>2) {
      Serial.print ("von: ");
      Serial.print (von);
      Serial.print (" bis: ");
      Serial.println (bis);      
      }
    
    A1CurrentPatternNumber = random(von, bis);  //pulse_blink hat eine Chance ausgewählt zu werden, wenn bis = 15 oder 16
    for(int i = 0; i < 8; i++)//Mit jedem Wert in last_choices vergleichen und wenn gleich neuen Random-Wert generieren
    {
      if(lc[i] == A1CurrentPatternNumber)
      {
        gleich = true;
        break;
      }
      else
      {
        gleich = false;
      }
    }
  }
  for(int i = 7; i > 0; i--)//Werte weiterschieben
  {
    lc[i] = lc[i-1];
  }
  lc[0] = A1CurrentPatternNumber;
  
}





void mainLoop()
{
  //static unsigned long timeStop;
  
  unsigned int waitingTime, newtime;
  int choice;
  int choice2;
  static int speicher_index=0;
    
  if(visualisation == true)
  {
    /*
    //Eigentlich würde ich hier lieber eine zufällig generierte Folge haben, die sowohl Ganz-Strip-Funktionen, als auch Übergänge und individuelle Funktionen beinhaltet! Natürlich muss in dem 
    //Moment jedem Abschnitt eine individuelle Funktion zugewiesen werden, das heisst je nach Straße oder Turm oder großem Turm, also vom Typ _FS, _FT, oder _FGT

    
    if (g_erster_aufruf)
    {
      //timeStop = millis();  // Startwert speichern bzw setzen
      Animation_counter = 0;  // setze den Zähler
      //waitingTime = 20000;  // Standard-Dauer des Effekts  
      // einmal alles löschen
        FastLED.clear();        
    }

    // Übergangseffekt einbauen?
    if (Animation_counter >= 3)
    {
      //waitingTime = 2000; // Ü-Effekt läuft kürzer
      EVERY_N_SECONDS(2)//alle 2 Sekunden
      {
        //choice = 0; // ==> individuell = false;
        //choice2 = random(6, 10);//eine Zahl von 6-9 muss hier gewählt werden!!!!!!!!!!!!
    
        FxCurrentPatternNumber = random(0, 5);//Hängt von der Größe der Liste ab -> momentan bis 5
       

        if (DEBUG>2) Serial.print("Übergangseffekt:");
        if (DEBUG>2) Serial.print(FxCurrentPatternNumber);
        // DEBUG
        //Serial.print("Übergangseffekt Nr:");
        //Serial.println(choice2); 
        
      }
      FxPatterns[FxCurrentPatternNumber] ();//jeweilige Funktion ausführen
      Animation_counter = 0;
      
    }

    else // KEIN Ü-Effekt --> Auswahl
    {
    
      //if (Animation_counter == 0 && !g_erster_aufruf)
      //{
      EVERY_N_SECONDS(80)//DEBUG, kann aber auch so bleiben
      {
      //Array mit Farb-Werten shuffeln!!!
        RGB_Array_shuffle();
        //DEBUG
        if (DEBUG>2) Serial.print("Shuffled!!");
        if (DEBUG>2) Serial.println();
        //Serial.print("Counter");
        //Serial.print(Animation_counter);
      //}
      }
      
      
      if (Animation_counter == 0 && helligkeit!=0 || Animation_counter == 0 && dimmer!=255)
      {
        helligkeit = 0;//Helligkeit zurücksetzen
        dimmer = 255;//Dimmer zurücksetzen
      }
      
      //waitingTime = 5000;  // normale Dauer des Effekts
      EVERY_N_SECONDS(20)//alle 20 Sekunden
      {
        choice = random(0, 2);//Für einzeln oder individuell(visualisierung)

        // DEBUG
        //choice=0;
        
        //choice2 = random(1, 5); // 1...3; Welche Funktion innerhalb von einzeln oder individuell ausgewählt wird
       
        //TEST: (DEBUG)
        //Animation_counter = 1;
        
        //DEBUG(muss wieder rein)
        Animation_counter += 1;
    
    
        // DEBUG
        //Serial.print(">>> choice:");
        //Serial.println(choice);
        //Serial.print(">>> choice2:");
        //Serial.println(choice2);
        if (DEBUG>2) Serial.print(">>> Animation_counter:");
        if (DEBUG>2) Serial.println(Animation_counter); 
      }    
    }
    
          
      

    // DEBUG
    //choice = 1;//setzen auf visualisierung für ganzen strip 
    //choice2 = 1;//setzen auf visualize_seven_spectrum
        
    // komplette oder individuelle Animation
    if(choice == 0)
      individuell = false;
    else
      individuell = true;


    if(individuell == true)
    {
      EVERY_N_SECONDS(20)
      {
        BsCurrentPatternNumber = random(0, 5);//Hängt von der Größe der Liste ab -> momentan bis 5
        if (DEBUG>2) Serial.print("individuell:");
        
        if (DEBUG>2) Serial.print(BsCurrentPatternNumber);
      }
      //DEBUG
      //BsCurrentPatternNumber = 0;

      
      BsPatterns[BsCurrentPatternNumber] ();//jeweilige Funktion ausführen
      
    }
    else  // nicht individuell
    {
      EVERY_N_SECONDS(20)
      {
        GsCurrentPatternNumber = random(0, 5);//Hängt von der Größe der Liste ab -> momentan bis 5
        if (DEBUG>2) Serial.print("nicht individuell:");
        if (DEBUG>2) Serial.print(GsCurrentPatternNumber);
      }
        
      GsPatterns[GsCurrentPatternNumber] ();//jeweilige Funktion ausführen
    }

    //Update des zweiten LED-ARRAYS(LED-WAND)
    //drei Zeilen nur für den Moment auskommentiert(bis die Led-Wand angelötet ist)
    //EVERY_N_SECONDS(20)
      //MxvCurrentPatternNumber = random(0, 5);//Hängt von der Größe der Liste ab -> momentan bis 5
    //MvxPatterns[MvxCurrentPatternNumber] ();//jeweilige Funktion ausführen

    //DEBUG
    //Serial.println(">>> Animation-Counter:");
    //Serial.println(Animation_counter);

    
    */
    //**********************BEAT-ANALYSE*********************************
    //beat-heavy oder nicht?
    
    analyse_array[speicher_index++] = Frequencies_One[0];
    speicher_index = speicher_index % 200;

    EVERY_N_SECONDS(10)
    {
      int h_beat_counter;
      h_beat_counter = 0;//heavy-Beat-Counter
      for(int i = 0; i < 200; i++)
      {
        if(analyse_array[i] > 800)
        {
          h_beat_counter++;
        }
      }

  
      if(h_beat_counter >= 3)
      {
        beat_heavy = true;
      }
      else
      {
        beat_heavy = false;
      }
    }
      
    
    //*************************HAUPTSCHLEIFE*****************************
    EVERY_N_SECONDS(20)
    {
      if(beat_heavy)
      {
        newPattern1(last_choices, 0, 16);

        //DEBUG
        //newPattern1(last_choices, 12, 12);
      }
      else
      {
        newPattern1(last_choices, 0, 14);
      }
      if (DEBUG>1)
      {
        Serial.print("Neuer Algorithmus: ");
        Serial.println(A1CurrentPatternNumber);
      }
    }


  
    if(A1Patterns[A1CurrentPatternNumber] () == 1)
    {
      if(index != 0)//zurücksetzen für Random-Wipe
      {
        index = 0;
      }

      if(index2 != 0 && index3 != NUM_LEDS)
      {
        index2 = 0;
        index3 = NUM_LEDS;
      }
      newPattern1(last_choices, 0, 10);
    }

    

    EVERY_N_SECONDS(80)
    {
      RGB_Array_shuffle();
    }

    
    Beat_scale();//LED-WAND-visualisationsfunktion
    
    

    //gleich = true;//Gleich zurücksetzen
    
    /*if(zuruecksetzen)//Für fade_to_black und fade_to_white
    {
      helligkeit = 0;//Helligkeit zurücksetzen
      dimmer = 255;//Dimmer zurücksetzen
      //neue Zufallszahlen generieren für auswahl
      zuruecksetzen = false;
    }*/
    //fill_solid(leds, ENDE_TURM4, CRGB::Green);
  }
  else  // keine Visualisierung; stattdessen Stadt
  {
    //FastLED.clear();//wenn man dies rauslääst schaltet sich die Stadt nach und nach an(über den aktuellen Stand des Arrays)
    if (DEBUG>2) Serial.print("keine Viz");
    //visualisation = false;
    Stadt();
    Pico();//LED_Wand für Stadt-Modus

    //Update des zweiten LED-ARRAYS(LED-WAND)
    //beide Zeilen nur für den Moment auskommentiert(bis die Led-Wand angelötet ist)
    //MvsCurrentPatternNumber = random(0, 4);//Hängt von der Größe der Liste ab -> momentan bis 4
    //MvsPatterns[MvsCurrentPatternNumber] ();//jeweilige Funktion ausführen


    //Für eine LED-Wand visualisierungsfunktion den Wert zurücksetzen(nur für diese Funktion)
    position_four_erster_aufruf = true;
    //Für strasse_fluss(Visualisierungsfunktion) den Wert zurücksetzen
    strasse_fluss_erster_aufruf = true;
    strasse_fluss2_erster_aufruf = true;
  }

  // jetzt die LEDs ansteuern(zum LED-STRIP die Daten rüberschicken)
  FastLED.show();
  // insert a delay to keep the framerate modest
  //FastLED.delay(1000/FRAMES_PER_SECOND); //war in der Demo-Datei so angegeben, hab ich jetzt reingepackt
  g_erster_aufruf = false;
}
