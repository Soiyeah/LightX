int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int del = 100;

long randNumber;

void setup() {

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);   
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);  

  

  randomSeed(analogRead(0));
  Serial.begin(9600);

}

void loop() {

allOff();


/* ----- PATTERN 1 -----------------*/

    del = 600;
    for(int i=0; i < 1; i++)
    {
    
     digitalWrite(led1,HIGH);
     delay(del);
     
     digitalWrite(led1,LOW);
     digitalWrite(led2,HIGH);
     delay(del);
     
     digitalWrite(led2,LOW);
     digitalWrite(led4,HIGH);
     delay(del);
     
     digitalWrite(led4,LOW);
     digitalWrite(led6,HIGH);
     delay(del);
     
     digitalWrite(led6,LOW);
     digitalWrite(led5,HIGH);
     delay(del);
     
     digitalWrite(led5,LOW);
     digitalWrite(led3,HIGH);
     delay(del);
     
     digitalWrite(led3,LOW);    
  }



/* ----- PATTERN 2 -----------------*/

    allOff();
    del = 1000;
    for(int i=0; i < 2; i++)
    {

     digitalWrite(led5,LOW);
     digitalWrite(led6,LOW);
     digitalWrite(led3,HIGH);
     digitalWrite(led4,HIGH);
     delay(del);
     
     digitalWrite(led3,LOW);
     digitalWrite(led4,LOW);
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
     delay(del);
     
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     digitalWrite(led5,HIGH);
     digitalWrite(led6,HIGH);
     delay(del);
     
     digitalWrite(led3,LOW);    
    }

/* ----- PATTERN 2 -----------------*/

  allOff();

  for(int i=0; i < 90; i++)
  {
    del = 2000/i+1;
    randNumber = random(8,14); // generate random number between 8 & 13 inclusive
    Serial.println(randNumber);
    Serial.println(i);
    Serial.println();
    
    digitalWrite(randNumber ,HIGH);
    delay(del);
    digitalWrite(randNumber ,LOW);
    delay(del);   

  }
  allOff();
  delay(4000);

  for(int i=0; i<10; i++)
  {
    allOn();
    delay(3000/(i+1));
    allOff();
    delay(3000/(i+1));
  }
  
}


void allOff()
{
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     digitalWrite(led3,LOW);
     digitalWrite(led4,LOW);
     digitalWrite(led5,LOW);
     digitalWrite(led6,LOW);     
}

void allOn()
{
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
     digitalWrite(led3,HIGH);
     digitalWrite(led4,HIGH);
     digitalWrite(led5,HIGH);
     digitalWrite(led6,HIGH);     
}








