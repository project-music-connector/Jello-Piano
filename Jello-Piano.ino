/* twelve tone synth
 * output 12 tones of scale (+ high C) to digital outs 1-13
 */

const int num = 13;        
int increment = 30;


//int tones[] = {1795, 1890, 1998, 2117, 2246, 2380, 2510, 2666, 2850, 3010, 3190, 3380, 3580};
//              C     Db    D     Eb    E     F     F#     G     Ab   A     Bb     B,   CC
int tones[] = {3580, 3380, 3190, 3010, 2850, 2666, 2510, 2380, 2246, 2117, 1998, 1890, 1795};
int pins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

int counters[num];
int states[num];

int analogSkip = 0;

// In the setup() loop, for each pin, set it as an output, and initialize its counter and state variables to 0.
void setup() {
  int i;
  for (i=0; i<num; i++) {
    pinMode(pins[i], OUTPUT);
    counters[i] = 0;
    states[i] = 0;
  } 
}


// In the loop() loop, for each pin, add increment to its counter value. If this value is greater than the tones value, substract the tones value from the counters value, 
void loop() {
  int i, j;
  int t;
  
  for (i=0; i<num; i++) {
     if ((counters[i]+=increment) > tones[i]) {
       counters[i] -= tones[i];
       states[i] = !states[i];
       digitalWrite(pins[i], states[i]);
     }
  }
}
