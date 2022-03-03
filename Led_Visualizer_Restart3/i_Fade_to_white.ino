/*******************Übergänge*********************/
int Fade_to_white()
{
  int value;
  long summe = 0;
  float perc = 0.05;
  CHSV col;
  
  if (DEBUG>0) Serial.println( "-- Fade_to_white");
  
  for ( int i = 0; i < NUM_LEDS; i++)
  {
    leds[i].setRGB (int((255-leds[i].r)*perc+leds[i].r), int((255-leds[i].g)*perc+leds[i].g), int((255-leds[i].b)*perc+leds[i].b));
    
/*    col = rgb2hsv_approximate(&leds[i]);
    value = col.val;
    value += int((255-value)*0.1);
    //leds[i] = CHSV(col.hue, col.sat, value);
    leds[i].setBrightness(value);
*/
    //summe += value;
    summe += leds[i].r;

  }

    if (DEBUG>1){
    Serial.print ("Summe: ");
    Serial.println (summe);
  }
  
  if(summe > 80000)
  {
    Serial.println ("Fade_to_white: fertig.");
    return 1;//fertig
  }
  else
  {
    return 0;//nicht fertig
  }
}
