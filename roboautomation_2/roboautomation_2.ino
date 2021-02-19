char data = 0;
void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  if (Serial.available() > 0)
  {
    data = Serial.read();       
    Serial.print(data);          
    Serial.print("\n");        
      if(data == 'F') 
      {            
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(10,HIGH);
         digitalWrite(11,LOW);
        Serial.println("car is moving Forward");
        Serial.print("\n"); 
      }   
       if(data == 'B') 
      {        
         digitalWrite(5,HIGH);
         digitalWrite(6,LOW);
         digitalWrite(10,LOW);
         digitalWrite(11,HIGH);
         Serial.println("car is moving Backward");
         Serial.print("\n");    
         
  }
  if(data == 'L') 
      {        
         digitalWrite(5,HIGH);
         digitalWrite(6,LOW);
         digitalWrite(10,HIGH);
         digitalWrite(11,LOW);
         Serial.println("car is moving Left");
         Serial.print("\n");    
         
  }
  if(data == 'R') 
      {        
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        digitalWrite(10,LOW);
        digitalWrite(11,HIGH);

         Serial.println("car is moving Right");
         Serial.print("\n");    
         
  }
  if(data == 'S') 
      {        
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
         Serial.println("car stop!!!!");
         Serial.print("\n");    
         
  }
  }
  
 
}


