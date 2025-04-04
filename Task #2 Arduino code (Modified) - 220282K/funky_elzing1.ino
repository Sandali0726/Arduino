// Name: Jayawardhana W.S.S
// Index No: 220282K


const int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Button inputs
const int frequencies[8] = {300, 400, 500, 600, 700, 800, 900, 1000}; // Frequencies for each button
const int speakerPin = 10; // Speaker output

// 7-segment display segment pins (Common Cathode)
const int segmentPins[7] = {11, 12, A0, A1, A2, A3, A4};

// Corrected 7-segment digit patterns (ACTIVE LOW)
const byte digits[8] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111  // 7
};

void setup() {
    for (int i = 0; i < 8; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP); // Set buttons as input with pull-up resistors
    }
    pinMode(speakerPin, OUTPUT);

    for (int i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
}

void displayDigit(int num) {
    if (num >= 0 && num < 8) {
        for (int i = 0; i < 7; i++) {
            digitalWrite(segmentPins[i], bitRead(digits[num], i)); // Active LOW fix
        }
    }
}

void clearDisplay() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(segmentPins[i], LOW); // Turn off all segments
    }
}

void loop() {
    int totalFreq = 0;
    int pressedKeys[8] = {0};
    int count = 0;

    for (int i = 0; i < 8; i++) {
        if (digitalRead(buttonPins[i]) == LOW) { // Button is pressed
            totalFreq += frequencies[i];
            pressedKeys[count++] = i; // Store the key number
        }
    }

    if (count > 0) {
        tone(speakerPin, totalFreq); // Play combined frequency tone

        // Display key numbers alternately
        unsigned long startTime = millis();
        while (millis() - startTime < 500) { // Display for 500ms
            for (int i = 0; i < count; i++) {
                displayDigit(pressedKeys[i]);
                delay(250); // Switch between keys faster
            }
        }
    } else {
        noTone(speakerPin); // Stop sound if no key is pressed
        clearDisplay(); // Turn off the 7-segment display
    }
}
