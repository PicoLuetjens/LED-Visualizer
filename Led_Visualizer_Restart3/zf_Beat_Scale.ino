//***************************LED-WAND-FUNKTION****************************
//Die Funktion lässt ein Viereck pulsieren und bei einem bestimmten Schwellenwert ändert sie die Farbe
void Beat_scale()
{
  if (DEBUG>0) Serial.println( "-- Beat_Scale");
  boolean change1 = true;
  boolean change2 = false;
  boolean change3 = false;
  boolean change4 = false;
  boolean change5 = false;
  boolean change6 = false;
  int current_state;//in welchem Scale sind wir gerade?
  //int last_current_state;

  //EVERY_N_MILLISECONDS(50)
  //{
     fill_solid(&leds2[0], NUM_LEDS2, CRGB(0, 0, 0));

  if(Frequencies_One[0] > 0 && Frequencies_One[0] <= 300)
  {
    current_state = 0;
    scale1();
  }

  else if(Frequencies_One[0] > 300 && Frequencies_One[0] <= 500)
  {
    current_state = 1;
    scale2();
  }
  
  else if(Frequencies_One[0] > 500 && Frequencies_One[0] <= 700)
  {
    current_state = 2;
    scale3();
  }

  else if(Frequencies_One[0] > 700 && Frequencies_One[0] <= 850)
  {
    current_state = 3;
    scale4();
  }

  if(Frequencies_One[0] > 850 && change1)
  {
    color_change1(); 
    change1 = false;
    change2 = true;
  }

  else if(Frequencies_One[0] > 850 && change2)
  {
    color_change2();
    change2 = false;
    change3 = true;
  }

  else if (Frequencies_One[0] > 850 && change3)
  {
    color_change3();
    change3 = false;
    change4 = true;
  }

  else if (Frequencies_One[0] > 850 && change4)
  {
    color_change4();
    change4 = false;
    change5 = true;
  }

  else if (Frequencies_One[0] > 850 && change5)
  {
    color_change5();
    change5 = false;
    change6 = true;
  }

  else if (Frequencies_One[0] > 850 && change6)
  {
    color_change6();
    change6 = false;
    change1 = true;
  }

  /*if(current_state != last_current_state)
    fill_solid(&leds2[0], NUM_LEDS2, CRGB(0, 0, 0));
  last_current_state = current_state;*/
  //DEBUG
  //fill_solid(&leds2[0], NUM_LEDS2, CRGB(0, 0, 0));
  
  //EVERY_SECONDS_(50) ENDE
  //}
}

void scale1()
{
  //leds2[27] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[28] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[27], 2, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  //leds2[35] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[36] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[35], 2, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
}

void scale2()
{
  //leds2[18] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[19] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[20] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[21] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[18], 4, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  leds2[26] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[29] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[34] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[37] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[42] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[43] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[44] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[45] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[42], 4, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
}

void scale3()
{
  //leds2[9] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[10] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[11] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[12] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[13] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[14] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[9], 6, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  leds2[17] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[22] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[25] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[30] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[33] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[38] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[41] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  leds2[46] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[49] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[50] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[51] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[52] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[53] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[54] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[49], 6, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
}

void scale4()
{
  //leds2[0] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[1] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[2] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[3] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[4] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[5] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[6] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[7] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[8] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[0], 9, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  //leds2[15] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[16] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[15], 2, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  //leds2[23] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[24] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[23], 2, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  //leds2[31] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[32] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[31], 2, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  //leds2[39] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[40] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[39], 2, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  //leds2[47] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[48] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[47], 2, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
  //leds2[55] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[56] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[57] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[58] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[59] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[60] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[61] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[62] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  //leds2[63] = CRGB(erste_farbe, zweite_farbe, dritte_farbe);
  fill_solid(&leds2[55], 9, CRGB(erste_farbe, zweite_farbe, dritte_farbe));
}

void color_change1()
{
  erste_farbe = random_rgb_values[1];
}

void color_change2()
{
  zweite_farbe = random_rgb_values[10];
  
}

void color_change3()
{
  dritte_farbe = random_rgb_values[12];
  
}

int color_change4()
{
  erste_farbe = random_rgb_values[5];
  
}

int color_change5()
{
  zweite_farbe = random_rgb_values[7];
  
}

int color_change6()
{
  dritte_farbe = random_rgb_values[0];
  
}
