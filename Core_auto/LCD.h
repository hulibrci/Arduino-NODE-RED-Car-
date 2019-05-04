  
/**************************************************
**                                              **
**                    LOGO                      **
**                                              **
**************************************************/
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  lcd.init();
  lcd.backlight(); 
  lcd.setCursor(2,0);
  lcd.print("Matej Mokry");
  delay (250);
  lcd.setCursor(1,1);
  lcd.print("BUILD 0.9 GNU ");
  delay (5000);
/**************************************************
**                                              **
**                Start                         **
**                                              **
**************************************************/
  {
	  lcd.clear();
	  lcd.setCursor(0, 0);
	  lcd.print("Ip 192.168.0.17");
	  lcd.setCursor(0, 1);
	  lcd.print("port 1880  GPL");
  }
