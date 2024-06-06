#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void loadingDisplay(){
  lcd.clear();
    lcd.print("Loading...");
  
    int i = 0;
    int l = 6;
  
    while(1){
      if(i < l){
        lcd.setCursor(i, 1);
        lcd.print("|");
      } else if (i < 16){
        lcd.setCursor(i-l+1, 1);
        for(int k=0; k<l; k++){
          lcd.print("|");
        }
        
        lcd.setCursor(i-l, 1);
        lcd.print(" ");
      } else {
        lcd.setCursor(i-l, 1);
        lcd.print(" ");
      }
      
      delay(300);
      i++;
      
      if(i >= (15+l+1)){
        i=0;
      }
    }
}

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop()
{
  loadingDisplay();
}
