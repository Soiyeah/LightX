
const int ledPin = 7;// the number of the LED pin

int ledState = LOW;             // ledState used to set the LED

unsigned long previousMillis = 0;     // will store last time LED was updated
const long interval = 200;           // interval at which to blink (milliseconds)

void setup() 
{
  pinMode(ledPin, OUTPUT);
}

void loop() 
{

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    
    previousMillis = currentMillis;    // save the last time you blinked the LED
    toggle();
    digitalWrite(ledPin, ledState);
    
  }

  
}

void toggle()
{
  
    if (ledState == LOW) 
    {
      ledState = HIGH;
    } 
    else 
    {
      ledState = LOW;
    }
}

