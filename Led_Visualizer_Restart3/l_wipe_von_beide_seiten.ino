/*******************Übergänge*********************/
int wipe_von_beiden_seiten()
{
  if (DEBUG>0) Serial.println( "-- wipe_von_beiden_seiten");
  
  //int wait_amount = 20;//Wartezeit bis zur nächsten LED
  
  int a = random_rgb_values[9];
  int b = random_rgb_values[10];
  int c = random_rgb_values[11];
  


  EVERY_N_MILLISECONDS(100)
  {
    fill_solid(&leds[0], index2, CRGB(a, b, c));
    index2+=15;

    fill_solid(&leds[index3], NUM_LEDS-index3, CRGB(a, b, c));
    index3-=15;

    if(index2 >= NUM_LEDS/2 && index3 <= (NUM_LEDS/2)+1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
