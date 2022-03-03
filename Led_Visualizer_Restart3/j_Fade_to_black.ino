/*******************Übergänge*********************/
int Fade_to_black()
{
  int fade_amount = 10;
  fadeToBlackBy(leds, NUM_LEDS, fade_amount);

   if (DEBUG>0) Serial.println( "-- Fade_to_black");

  for ( int i = 0; i < NUM_LEDS; i++)
  {
    if(leds[i].r <= 0)
    {
      return 1; 
    }
    else
    {
      return 0;
    }
  }
}
