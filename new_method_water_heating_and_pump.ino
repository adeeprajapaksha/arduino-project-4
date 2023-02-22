#define start 2
#define stop 3
#define LS1 19
#define LS2 18
#define D1 16
#define D2 17
#define D3 20

#define pump1 4
#define pump2 5
#define minipump 8
#define red 46
#define green 6
#define heater 9
#define conveyor 7

int b;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(start,INPUT_PULLUP);
  pinMode(stop,INPUT_PULLUP);
  pinMode(LS1,INPUT);
  pinMode(LS2,INPUT);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,INPUT);

  pinMode(pump1,OUTPUT);
  pinMode(pump2,OUTPUT);
  pinMode(minipump,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(heater,OUTPUT);
  pinMode(conveyor,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
if(b==1){
  digitalWrite(pump1,LOW);
  digitalWrite(pump2,LOW);
  digitalWrite(minipump,LOW);
  digitalWrite(conveyor,LOW);
  digitalWrite(heater,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  b=2;
}
if(b==2){
  if(digitalRead(start)==0&&digitalRead(LS1)==1){
    b=3;
  }
}
if(b==3){
  digitalWrite(pump1,HIGH);
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  b=4;
}
if(b==4){
if(digitalRead(LS2)==1){
b=5;  
}
}
if(b==5){
  digitalWrite(pump1,LOW);
  digitalWrite(heater,HIGH);
  delay(5000);
  digitalWrite(heater,LOW);
  digitalWrite(pump2,HIGH);
  b=6;
}
if(b==6){
  if(digitalRead(LS1)==HIGH){
    b=1;
  }
}
}
