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
    val = Serial.read();
    Serial.println(val);
  }

  if(val == '1')
  {
    digitalWrite(13,HIGH);
  }
  else if(val == '2')
  {
    digitalWrite(13,LOW);
  }
  
  else if(val == '3')
  {
    for(int i=0; i < 5; i++)
    {
    
     digitalWrite(13,HIGH);
     delay(500);
     
     digitalWrite(13,LOW);
     digitalWrite(12,HIGH);
     delay(500);
     
     digitalWrite(12,LOW);
     digitalWrite(11,HIGH);
     delay(500);
     
     digitalWrite(11,LOW);
     digitalWrite(10,HIGH);
     delay(500);
     
     digitalWrite(10,LOW);
     digitalWrite(9,HIGH);
     delay(500);
     
     digitalWrite(9,LOW);
     digitalWrite(8,HIGH);
     delay(500);
     
     digitalWrite(8,LOW);
     delay(500);
    }
    
  }
  delay(100);


}









