void RGB_Array_shuffle()
{
  if (DEBUG>0) Serial.println( "-- RGB_Array_shuffle");
  
  int questionCount = sizeof(random_rgb_values) / sizeof(random_rgb_values[0]);
  for (int i = 0; i < questionCount; i++)
  {
    int n = random(0, questionCount);  // Integer from 0 to questionCount-1
    int temp = random_rgb_values[n];
    random_rgb_values[n] =  random_rgb_values[i];
    random_rgb_values[i] = temp;
  }
}
