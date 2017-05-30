
boolean connected = false;
String answer ="";
String Message = "";

void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
Serial.begin(9600);
Serial1.begin(115200);
Serial.println("sim900 Turned on");

}


void loop() {


while(!connected){
  if(Serial1.available()){
      Serial.print("connected");

    delay(3000);
    connected = true;
    Serial1.print("AT+CMGF=1\r");
    
  }
}


while(Serial.available()){
String command = Serial.readString();
Serial1.print(command);
}



while(Serial1.available()){
answer = Serial1.readString();
Serial.println(answer);
}

if(answer.indexOf("+CMT")>0){
  int pos_start_message = answer.lastIndexOf('"') + 1;
  Message = answer.substring(pos_start_message);
  Message.trim();
  Serial.println(Message);
  Serial.println(Message.length());
  answer = "";
  
}

if(Message == "on"){
  digitalWrite(7,HIGH);
  
}
else if(Message =="off"){
    digitalWrite(7,LOW);

}


}






