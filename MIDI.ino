/*
 * MIDI.ino
 * Plays preset or custom songs on buzzer
 * Doesn't actually use MIDI
 */

const int buttonPin = 2;
const int buzzerPin = 8;

// potentiometers
const int potPin1 = A5;
const int potPin2 = A0;

int buttonState = 0;
int noteVal = 0;
int modeVal = 0;

// fairy fountain frequencies
float fairy[] = {
  440, 293.66, 233.08, 196.00, 
  392.00, 293.66, 233.08, 196.00,
  369.99, 293.66, 233.08, 196.00,
  392.00, 293.66, 233.08, 196.00,
  392.00, 261.63, 220.00, 174.61,
  349.23, 261.63, 220.00, 174.61,
  329.63, 261.63, 220.00, 174.61,
  349.23, 261.63, 220.00, 174.61,
  349.23, 233.08, 196.00, 164.81,
  329.63, 233.08, 196.00, 164.81,
  311.13, 233.08, 196.00, 164.81,
  329.63, 233.08, 196.00, 164.81,
  329.63, 220.00, 174.61, 146.83,
  293.66, 220.00, 174.61, 146.83,
  277.18, 220.00, 174.61, 146.83,
  293.66, 220.00, 174.61, 146.83,
  440, 293.66, 233.08, 196.00, 
  392.00, 293.66, 233.08, 196.00,
  369.99, 293.66, 233.08, 196.00,
  392.00, 293.66, 233.08, 196.00,
  466.16, 311.13, 261.63, 185.00,
  440.00, 311.13, 261.63, 185.00,
  415.30, 311.13, 261.63, 185.00,
  440.00, 311.13, 261.63, 185.00,
  523.25, 293.66, 233.08, 196.00,
  466.16, 293.66, 233.08, 196.00,
  440.00, 293.66, 233.08, 196.00,
  466.16, 293.66, 233.08, 196.00,
  440.00, 233.08, 196.00, 164.81,
  392.00, 233.08, 196.00, 164.81,
  349.23, 233.08, 196.00, 164.81,
  329.63, 233.08, 196.00, 164.81,
};

// Kindom Hearts
float hearts[] = {
  523.25, 523.25, 0, 523.25,
  392.00, 392.00, 0, 392.00,
  349.23, 349.23, 0, 349.23,
  587.33, 587.33, 0, 587.33,
  523.25, 523.25, 0, 523.25,
  392.00, 392.00, 0, 392.00,
  349.23, 349.23, 0, 349.23,
  587.33, 587.33, 0, 587.33,
  622.25, 622.25, 0, 622.25,
  587.33, 587.33, 0, 587.33,
  783.99, 783.99, 0, 783.99,
  698.46, 698.46, 0, 698.46,
  622.25, 622.25, 0, 622.25,
  587.33, 587.33, 0, 587.33,
  523.25, 523.25, 0, 523.25,
  466.16, 466.16, 0, 466.16
};

// Mario underwater
float mario[] = {
  293.66, 329.63, 369.99, 
  392.00, 440.00, 466.16, 
  493.88, 0, 493.88, 
  493.88, 0, 392.00, 
  659.25, 659.25, 659.25, 
  622.25, 622.25, 622.25, 
  659.25, 659.25, 659.25, 
  392.00, 523.25, 587.33,
  659.25, 659.25, 659.25, 
  622.25, 622.25, 698.46, 
  659.25, 659.25, 659.25, 
  0, 0, 0,
  587.33, 587.33, 587.33,
  554.37, 554.37, 554.37, 
  587.33, 587.33, 587.33,
  392.00, 493.88, 554.37,
  587.33, 587.33, 587.33,
  392.00, 392.00, 698.46,
  659.25, 659.25, 659.25, 
  0, 0, 392.00,
  783.99, 783.99, 0,
  783.99, 783.99, 0,
  783.99, 783.99, 0,
  783.99, 880.00, 783.99,
  698.46, 698.46, 0,
  698.46, 698.46, 0,
  698.46, 698.46, 0,
  698.46, 783.99, 698.46,
  659.25, 659.25, 659.25,
  440.00, 493.88, 698.46,
  659.25, 659.25, 493.88,
  523.25, 523.25, 523.25,
  0, 0, 0
};

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
}

void loop() {
  // read controls
  buttonState = digitalRead(buttonPin);
  modeVal = analogRead(potPin1);
  noteVal = analogRead(potPin2);

  // five modes depending on first potentiometer
  if(modeVal < 200)
    song(fairy, sizeof(fairy)/sizeof(float), 0, 199);
  else if(modeVal < 400)
    song(hearts, sizeof(hearts)/sizeof(float), 200, 399);
  else if(modeVal < 600)
    song(mario, sizeof(mario)/sizeof(float), 400, 599);
  else if(modeVal < 800)
    tones();
  else
    weeoo();
}

// play a note from the C scale
void tones() {
  if(buttonState == HIGH) {
    if(noteVal < 128 )
      tone(buzzerPin, 261.63);
    else if(noteVal < 256 )
      tone(buzzerPin, 293.66);
    else if(noteVal < 384 )
      tone(buzzerPin, 329.63);
    else if(noteVal < 512 )
      tone(buzzerPin, 349.23);
    else if(noteVal < 640 )
      tone(buzzerPin, 392.00);
    else if(noteVal < 768 )
      tone(buzzerPin, 440.00);
    else if(noteVal < 896 )
      tone(buzzerPin, 493.88);
    else
      tone(buzzerPin, 523.25);
  }
  else
    noTone(buzzerPin);
}

// play a continuous slide of frequencies
void weeoo() {
  if(buttonState == HIGH)
    tone(buzzerPin, noteVal);
  else
    noTone(buzzerPin);
}

// play a preset song
void song(float arr[], int s, int minRange, int maxRange) {
  // loop through all notes
  for(int i = 0; i < s; i++) {
    // check if mode has changed
    modeVal = analogRead(potPin1);
    if(modeVal < minRange || modeVal > maxRange)
      return;

    // play the note or nothing if below threshold
    if(arr[i] > 10)
      tone(buzzerPin, arr[i]);
    else
      noTone(buzzerPin);

    // each note is .25 seconds
    delay(250);
  }
}

