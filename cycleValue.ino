/*  cyclic inc/dec value constrained
    increment or decrement by an integer value, (normally +1 or -1)
    but cycle between min and max constraints
        EX: dec by -1    4  3  2  1    4  3  2  1
            inc by +2   -4 -2  0  2   -4 -2  0  2
    compiled with for Arduino (C++) Teensy 3.2
    Nov 12, 2019

    See https://stackoverflow.com/questions/27615050/how-to-efficiently-cycle-consecutive-numbers-c/58841622#58841622

*/

int16_t cycleIncDec(int16_t x, int16_t dir, int16_t xmin, int16_t xmax) {
    // inc/dec with constrained range
    // supplied xmax must be greater than xmin
    x += dir;
    if      (x > xmax) x = xmin;
    else if (x < xmin) x = xmax;
    return x;
}

// test different input cases to evaluate cycling
void setup() {
    Serial.begin(115200);
    while (!Serial && (millis() < 5000)) {} // include timeout if console window isn't opened

    int num = 15;
    Serial.printf("Test cycleIncDec()\n");

    int16_t z = 11;
    Serial.printf("\nz:%4d:  ",z);
    for (int i = 0; i < num; i++) {
        z = cycleIncDec(z,1,0,6);
        Serial.printf(" %4d",z);
    }
    z = 4;
    Serial.printf("\nz:%4d:  ",z);
    for (int i = 0; i < num; i++) {
        z = cycleIncDec(z,-1,-8,10);
        Serial.printf(" %4d",z);
    }
    z = -8;
    Serial.printf("\nz:%4d:  ",z);
    for (int i = 0; i < num; i++) {
        z = cycleIncDec(z,1,-13,-8);
        Serial.printf(" %4d",z);
    }
    z = -190;
    Serial.printf("\nz:%4d:  ",z);
    for (int i = 0; i < num; i++) {
        z = cycleIncDec(z,-2,-200,-170);
        Serial.printf(" %4d",z);
    }
    z = 1;  // if z is not an even multiple of step, it will yield unintended values
    Serial.printf("\nz:%4d:  ",z);
    for (int i = 0; i < num; i++) {
        z = cycleIncDec(z,5,0,20);
        Serial.printf(" %4d",z);
    }
}


void loop() {}

