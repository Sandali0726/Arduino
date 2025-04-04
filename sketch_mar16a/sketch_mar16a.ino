// C++ code
//
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(8, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(8, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(8, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
}