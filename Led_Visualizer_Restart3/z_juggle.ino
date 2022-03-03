/************************Gesamt-Strip-Funktionen**************************///NOCH NICHT FERTIG!!!


int juggle() {

  if (DEBUG>0) Serial.println( "-- juggle");

  // sieben verteilte Punkte, je einer pro Frequenzband, wabern sinusmäßig auf und ab; zusätzliche Bwewegung je nach Lautstärke

  long value;
  int pos, wavepos, num;
  int bpm = 1;
  int max_Ausschlag = 10;
  
  fadeToBlackBy(leds, NUM_LEDS, 40);
  byte dothue = 0;

  for (num=0 ; num<7 ; num++){
    value = map(Frequencies_One[num], 0, 1023, -max_Ausschlag, max_Ausschlag);
    pos = int((0.5*NUM_LEDS-max_Ausschlag) * sin (2*PI * (millis()*bpm/60000. + num/7.)) + 0.5*NUM_LEDS + value);
    leds[pos] |= CHSV(led_hue[num], 200, 255);
    dothue += 32;

    if (num == 0) Serial.println(pos);
  }


  // Sicherheitscheck
  if (pos > NUM_LEDS - 8) pos = NUM_LEDS - 8;
  if (pos < 0)            pos = 0;
  return 0;
}
