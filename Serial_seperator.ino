#define ldir 12
#define lpwm 5
#define lcha 2
#define lchb 8

#define rdir 13
#define rpwm 6
#define rcha 3
#define rchb 9

String dirStr="";
String distStr="";
String SpeedStr="";
int dist;
int Speed;
volatile long lchA_tic = 0;
volatile bool lchBset;
volatile long rchA_tic = 0;
volatile bool rchBset;
int a=0;
int b=0;

void setup() {
  
  Serial.begin(115200);
  pinMode(ldir,OUTPUT);
  pinMode(rdir,OUTPUT);
  encoder_setup();
  int a=0;
  int b=0;
  lchA_tic=0;
  rchA_tic=0;

}

void loop() {

  while(Serial.available()>0)
  {
    dirStr=Serial.readStringUntil(':');
    Serial.read();
    distStr=Serial.readStringUntil(':');
    Serial.read();
    SpeedStr=Serial.readStringUntil(':');
    Serial.read();
    dist=distStr.toInt();
    Speed=SpeedStr.toInt();
  }
  if(dirStr=="r")
  move_reverse();
  if(dirStr=="f")
  move_forward();
  if(dirStr=="fr")
  move_forwardright();
  if(dirStr=="fl")
  move_forwardleft();
  if(dirStr=="st")
  move_stop();
  
if(a!=lchA_tic || b!=rchA_tic)
  {
  Serial.print("e");
  Serial.print("\t");
  Serial.print(lchA_tic);
  Serial.print("\t");
  Serial.print(rchA_tic);
  Serial.print("\n");
  a=lchA_tic; 
  b=rchA_tic;
  }
  dirStr=""; 
}

void move_reverse()
{
  digitalWrite(ldir,HIGH);
  digitalWrite(rdir,LOW);
  analogWrite(lpwm,Speed);
  analogWrite(rpwm,Speed);
}

void move_forward()
{
  digitalWrite(ldir,LOW);
  digitalWrite(rdir,HIGH);
  analogWrite(lpwm,Speed);
  analogWrite(rpwm,Speed);
}

void move_forwardleft()
{
  digitalWrite(ldir,HIGH);
  digitalWrite(rdir,HIGH);
  analogWrite(lpwm,Speed);
  analogWrite(rpwm,Speed);
}

void move_forwardright()
{
  digitalWrite(ldir,LOW);
  digitalWrite(rdir,LOW);
  analogWrite(lpwm,Speed);
  analogWrite(rpwm,Speed);
}
void move_stop()
{
  //digitalWrite(ldir,LOW);
  //digitalWrite(rdir,LOW);
  analogWrite(lpwm,0);
  analogWrite(rpwm,0);
}

void encoder_setup()
{
  pinMode(lcha,INPUT_PULLUP);
  pinMode(lchb,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(lcha),Left_enc,RISING);
  
  pinMode(rcha,INPUT_PULLUP);
  pinMode(rchb,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(rcha),Right_enc,RISING);
  Serial.println("encoders are setup");  
}

void Left_enc()
{
  lchBset = digitalRead(lchb);
  lchA_tic -= lchBset ? -1 : +1;
  //Serial.print("Left");
  //Serial.print("\t");
  //Serial.println(lchA_tic);
}

void Right_enc()
{
  rchBset = digitalRead(rchb);
  rchA_tic -= rchBset ? +1 : -1;
   //Serial.print("Right");
  //Serial.print("\t");
  //Serial.println(rchA_tic);
}
