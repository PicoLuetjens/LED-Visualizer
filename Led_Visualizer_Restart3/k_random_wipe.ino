/*******************Übergänge*********************/
int random_wipe()
{
  if (DEBUG>0) Serial.println( "-- random_wipe");
  
  //int wait_amount = 20;//Wartezeit bis zur nächsten LED
  
  int a = random_rgb_values[0];
  int b = random_rgb_values[1];
  int c = random_rgb_values[2];
  


  EVERY_N_MILLISECONDS(100)
  {
    fill_solid(&leds[0], index, CRGB(a, b, c));
    index+=30;

    if(index >= NUM_LEDS-1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  

  /*for (int i = 0; i <= NUM_LEDS; i+=3)
  {
    EVERY_N_MILLISECONDS(100)//alle 0,1 Sekunden neue LED anmachen
    {
      int j = 
      leds[i] = CRGB(a, b, c);
    }
    
  }
   
   //delay(1000);*/
 /*EVERY_N_MILLISECONDS(100)
 {
    for(int i = 0; i <= NUM_LEDS; i+=3)
    {
      fill_solid(leds, i, CRGB(a, b, c));
    }
 }*/
 //fill_solid(leds, NUM_LEDS, CRGB::Red);
}
