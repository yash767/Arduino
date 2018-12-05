int count=0;
int dist=0;
#define in 14
#define out 19
#define relay 2
#define IRinput A0
#define IRoutput A1
void input()
{
  count++;
  if(count>0)
  {
    digitalWrite(relay,HIGH);
    Serial.print("Number of people in the room is : ");
    Serial.print(count);
    Serial.print("\n");
  }
  delay(2000);
  
  }
void output()
{
  
  count--;  
  if(count<0)
  count = 0;
  if(count>0)
  {
    digitalWrite(relay,HIGH);
    Serial.print("Number of people in the room is : ");
    Serial.print(count);
    Serial.print("\n");
  }
  delay(2000);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in,INPUT);
  pinMode(out,INPUT);
  pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(count==0)
  {
  Serial.print("No people in the room");
  Serial.print("\n");
  delay(2000);
  }
  if(analogRead(IRinput)<500)
  input();
  else if(analogRead(IRoutput)<500)
  output();
  
  
}
