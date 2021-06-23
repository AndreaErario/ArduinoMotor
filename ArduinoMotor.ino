int motorPin1 = 2;
int motorPin2 = 3;
int buttonPin = 10;

int state = LOW;
int reading;
int previous = LOW;

long time = 0;
long timer;
long debounce = 200;
long stateTime;

int rotation = HIGH;

void setup() {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    reading = digitalRead(buttonPin);

    if (reading == HIGH && previous == LOW && millis() - time > debounce) {
        if (state == LOW) {
            state = HIGH;
            stateTime = millis();
        } else {
            state = LOW;
        }

        time = millis();
    }
 
    if (state == HIGH) {
        if (timer - stateTime <= 10000) {
            digitalWrite(motorPin1, rotation);
            digitalWrite(motorPin2, !rotation);
        } else {
            rotation = !rotation;
            stateTime = millis();
        }
    } else {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
    }

    previous = reading;
    timer = millis();
} 
