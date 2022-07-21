#define DEBOUNCE 50
const int button = 2, relay = 10;
int lastButtonState = HIGH, buttonState, relayState = LOW;
bool pressed = false;
unsigned long previousTime = 0;

void setup(){
    pinMode(button, INPUT_PULLUP);                          
    pinMode(relay, relayState);
    digitalWrite(relay, relayState);
}

void loop(){
    buttonState = digitalRead(button);
    if(lastButtonState != buttonState){
        pressed = true;
        previousTime = millis();
    }
    if(pressed){
        if(millis() - previousTime >= DEBOUNCE){
            pressed = false;
            if(buttonState == LOW){    
                digitalWrite(relay, (relayState = !relayState));   
            }
        }
    }
    lastButtonState = buttonState;
}