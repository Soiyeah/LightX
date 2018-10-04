
int led1 = 12;      //Initialize led pins.
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int led6 = 7;

int i = 1;

boolean soundstate;

unsigned long currentMillis;

unsigned long prevMillisPtn1=0;
unsigned long prevMillisLED2=0;
unsigned long prevMillisLED3=0;
unsigned long prevMillisLED4=0;
unsigned long prevMillisLED5=0;
unsigned long prevMillisLED6=0;

int intervalPtn1 = 50;

int del = 150;


void setup() {


  Serial.begin(9600);
  pinMode(3,INPUT); //SIG of the Parallax Sound Sensor connected to Digital Pin 3

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);   
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);


}

void loop() 
{

  
  currentMillis = millis();
  upSweep();


  

} //------------------- end of loop() ----------------------//



void upSweep() // Pattern 1 - Up sweep
{

  soundstate = digitalRead(3);

  if (soundstate == 1) 
  {
    switch(i)
    {
        case 1:

          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          digitalWrite(led6, HIGH);
          delay(del);
          digitalWrite(led4, LOW);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW); 

            i++;
             break;

        case 2:

          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          delay(del);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
            
            i++;
             break;

        case 3:

          digitalWrite(led1, HIGH);
          delay(del);
          digitalWrite(led1, LOW);
          i++;  
             break;
             
        default:
            i = 1;
    }           
  }
  else
  {
    allOff();
  }
}


void allOff()
{
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
}


void allOn()
{
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
}








