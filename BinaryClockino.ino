int mins[]={10,9,8,7,6,5};
int hrs[]={4,3,2,1,0};
int i;
int hr0=20,minn0=45;// <---- Postavi vrijeme ovdje // 17 sec, 11h 13m   0.5 mijenja
unsigned long t,hr,minn,sec,m;

void setup() {
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  for(i=0;i<13;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);
  for(i=0;i<5;i++){
    digitalWrite(i,HIGH);
    delay(250);
    digitalWrite(i,LOW);
  }
  for(i=10;i>=5;i--){
    digitalWrite(i,HIGH);
    delay(250);
    digitalWrite(i,LOW);
  }
  digitalWrite(12,HIGH);
  digitalWrite(LED_BUILTIN,HIGH);

  delay(500);
  for(i=0;i<5;i++){
    digitalWrite(i,HIGH);
    delay(150);
  }
  for(i=10;i>=5;i--){
    digitalWrite(i,HIGH);
    delay(150);
  }
  delay(200);
  for(i=11;i>=0;i--){
    digitalWrite(i,LOW);
  }
  digitalWrite(12,LOW);
  digitalWrite(LED_BUILTIN,LOW);
  delay(250);
  t=hr0;
  for(i=0;i<5;i++){
    digitalWrite(hrs[i],t%2);
    t/=2;
    if(hrs[i])
    delay(100);
  }
  t=minn0;
  for(i=0;i<6;i++){
    digitalWrite(mins[i],t%2);
    t/=2;
    if(mins[i])
    delay(100);
  }
}

void loop() {
  m=millis();
  t=m/1000+m/2375294;
  hr=hr0+((t/3600)%24);
  minn=(t%3600)/60+minn0;
  
  if(minn>59){
    minn-=60;
    hr++;
  }
  if(hr>23)
    hr-=24;

  for(i=0;i<5;i++){
    digitalWrite(hrs[i],hr%2);
    hr/=2;
  }
  for(i=0;i<6;i++){
    digitalWrite(mins[i],minn%2);
    minn/=2;
  }
  
  digitalWrite(12,t%2);
  digitalWrite(LED_BUILTIN,t%2);
  
  if(digitalRead(A0)==LOW){
    minn0++;
    if(minn0>59)
      minn0-=60;
    delay(150);
  }
  if(digitalRead(A1)==LOW){
    hr0++;
    if(hr0>23)
      hr0-=24;
    delay(150);
  }  
}
