#include <LiquidCrystal.h>
// This is the library for LCD panel
int senRead= A0;
int val = 0;
int glucoselevel = 0;
int arr[50];
int counterelements = 0;
int correctedglucoselevel = 0;
// All the varialbles are mentioned above
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
// We have activated the pins for lcd panel

// We have two functions in arudiono code; setup and loop
void setup() 
{
  Serial.begin(9600);
  // used for serial montior of arudino
  pinMode(senRead, INPUT);
  // declared pin to give input, sensor will get input form this sensor.
  lcd.begin(16,2);
  // initialising the led, 16 horizontally and 2 vertically
  lcd.clear( );
  // clearing screen for the operation
}
// setup works only once, if there's no loop

int average(int arry[50])
{
  int sum = 0;
  int avg = 0;
  for(int i =0; i<50; i++)
  {
     sum = sum + arry[i];
  }
  avg = sum / 50;
  return avg;
}
// the value from the above sensor in added 
void loop() 
{ 
  val = analogRead(senRead);
  glucoselevel = (8*pow(10,-5)*pow(val,2))+ (0.1873*val) + 46.131;
  glucoselevel = constrain(glucoselevel, 60, 160);
  if (glucoselevel > 60)
   {
     arr[counterelements] = glucoselevel;
      if(counterelements == 49)
     {
       correctedglucoselevel= average(arr);
       Serial.print(" Glucose Level = ");
       Serial.print(correctedglucoselevel);
       Serial.println(" mg/dl");
       lcd.setCursor(0,0);
       lcd.print("Glucose level = ");
       lcd.setCursor(5,1);
       lcd.print(correctedglucoselevel);
       lcd.setCursor(10,1);
       lcd.print(" mg/dl");
       counterelements = 0;
     }
      counterelements++;
   }
   else
   {
    lcd.setCursor(0,0);
    lcd.print("please put your");
    lcd.setCursor(0,1);
    lcd.print("earlobe in sensor");
   }
   delay(20);
}
