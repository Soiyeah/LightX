int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;

int del = 200;
char val;

void setup() 
{
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);   
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT); 
  
  Serial.begin(9600);

}

void loop() 
{

  if(Serial.available())
  {
    del = Serial.read();
    Serial.println(del);

    if(del <= 5)
    {
      del = 100;
    }
  }


    
 /* ----- PATTERN 1 -----------------*/
    
    
    for(int i=0; i < 5; i++)
    {


  if(Serial.available())
  {
    del = Serial.read();
    Serial.println(del);

    if(del <= 5)
    {
      del = 100;
    }
  }
      
    
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

    
  
  delay(100);


}









