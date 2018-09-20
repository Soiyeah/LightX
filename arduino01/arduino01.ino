int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int led5 = 8;
int led6 = 7;

int del = 200;
String fullStr, subStr;

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
    
    fullStr = Serial.readString();

    while((fullStr.length() >= 2))
    {
        subStr = fullStr.substring(0,2);
        Serial.println("sub string: "+subStr);
        ledControl(subStr);
        fullStr.remove(0,2);

    }
    
    
    //ledControl();
    
  }

}


void ledControl(String str)
{
  
  if(str.equals("1H"))
  {
    digitalWrite(led1,HIGH);
  }
  else if(str.equals("2H"))
  {
    digitalWrite(led2,HIGH);
  } 
  else if(str.equals("3H"))
  {
    digitalWrite(led3,HIGH);   
  }
    else if(str.equals("4H"))
  {
    digitalWrite(led4,HIGH);
  }   
  else if(str.equals("5H"))
  {
    digitalWrite(led5,HIGH);   
  }
    else if(str.equals("6H"))
  {
    digitalWrite(led6,HIGH);   
  }

  else if(str.equals("1L"))
  {
    digitalWrite(led1,LOW);
  } 
  else if(str.equals("2L"))
  {
    digitalWrite(led2,LOW);
  } 
  else if(str.equals("3L"))
  {
    digitalWrite(led3,LOW);   
  }
    else if(str.equals("4L"))
  {
    digitalWrite(led4,LOW);
  } 
  else if(str.equals("5L"))
  {
    digitalWrite(led5,LOW);   
  }
    else if(str.equals("6L"))
  {
    digitalWrite(led6,LOW);   
  }

  delay(10);
  
}








