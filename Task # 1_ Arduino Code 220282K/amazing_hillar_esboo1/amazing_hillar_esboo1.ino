// Name: Jayawardhana W.S.S
// Index No: 220282K

const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Button inputs
const int frequencies[8] = {300, 400, 500, 600, 700, 800, 900, 1000}; // Frequencies for each button
const int speakerPin = 10; // Speaker output

void setup() {
    for (int i = 0; i < 8; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP); // Set button pins as input with internal pull-up
    }
    pinMode(speakerPin, OUTPUT);
}

void loop() {
    int totalFreq = 0;
    bool keyPressed = false;

    for (int i = 0; i < 8; i++) {
        if (digitalRead(buttonPins[i]) == LOW) { // Button is pressed
            totalFreq += frequencies[i];
            keyPressed = true;
        }
    }

    if (keyPressed) {
        tone(speakerPin, totalFreq); // Play combined frequency tone
        delay(20); // Maintain tone for 20ms if key is momentarily pressed
    } else {
        noTone(speakerPin); // Stop sound if no key is pressed
    }
}
