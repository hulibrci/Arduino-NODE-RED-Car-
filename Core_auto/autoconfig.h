Serial.println("Zadaj rychlot");
while (Serial.available() == 0) {}
speeed = Serial.parseInt();

if (speeed <200)
{
Serial.print("Tvoja rychlost je ");
Serial.print(speeed);
Serial.println("");
delay(90);
Serial.println("OK");
//rok
  Serial.println("Zadaj aktualni rok");
  while (Serial.available() == 0) {}
  rok = Serial.parseInt();
  Serial.println("OK");
   //mesiac
   
    Serial.println("Zadaj aktualni mesiac");
    while (!Serial.available() == 0) {}
    mesiac = Serial.parseInt();

      if (mesiac <12)
    {
    Serial.println("OK");
    
       //den
        Serial.println("Zadaj aktualni den");
        while (Serial.available() == 0) {}
        den = Serial.parseInt();

        if (den <31)
        {
        Serial.println("OK");


        //hod
          Serial.println("Zadaj hod");
          while (Serial.available() == 0) {}
          hod = Serial.parseInt();

          if (hod <24)
          {
          Serial.println("OK");
          //min
            Serial.println("Zadaj min");
            while (Serial.available() == 0) {}
            minuti = Serial.parseInt();

            if (minuti <60)
            {
            Serial.println("OK");

          //rekap
            myRTC.setDS1302Time(0, minuti, hod, 6, den, mesiac, rok);
            Serial.println("Rekapitulácia");
            Serial.println("");
            Serial.println("rychlost");
            Serial.print(speeed);
            Serial.println("");
            Serial.println("Datum  cas");
            Serial.print("/");
            Serial.print(mesiac);
            Serial.print("/");
            Serial.print(rok);
            Serial.print("  ");
            Serial.print(hod);
            Serial.print(":");
            Serial.print(minuti);
            Serial.println("");
            Serial.println("Vseko je nastavene teraz staci ist len na rpi3 na porte 1880 a ip 192.168.0.22 ");
            }
            else
            {
            Serial.println("ERROR");
            Serial.println("Reconfigurate");
            minuti = 0;
            Serial.println("OK");
            }
          }
          else
          {
          Serial.println("ERROR");
          Serial.println("Reconfigurate");
          hod = 0;
          Serial.println("OK");
          }
        }
        else
        {
        Serial.println("ERROR");
        Serial.println("Reconfigurate");
        den = 0;
        Serial.println("OK");
        }
    }
    else
    {
    Serial.println("ERROR");
    Serial.println("Reconfigurate");
    mesiac = 0;
    Serial.println("OK");
    }
}
else
{
  Serial.print("Maximum je 200");
  delay(700);
  Serial.println("");
  Serial.println("ERROR");
  delay(90);
  Serial.println ("Reconfigurate");
  speeed = 0;
  delay(200);
  Serial.println("OK");

}
///koniec rychlost 



