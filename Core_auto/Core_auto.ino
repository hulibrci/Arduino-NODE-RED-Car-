


/*********************************************************************************
**                                                                              **
**   Daskama Jokkie 2018/19     Štart=16.1.2018    Build 0.7                    **
**   #fix clock                                                                 **
**                                                                              **
**                                                                              **
**                                                                              **
**                                                                              **
**                                                                              **
**   Last Edit:22.9.2018                                  Matej Mokrý           **
**********************************************************************************/


/* 
 * This file is part of the jokkie distribution .
 * Copyright (c) 2019 Matej Mokrý.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */




#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>   
#include "int.h" 




void setup() {

#include "LCD.h"  

Serial.begin(9600);
pinMode(kolLB,OUTPUT); 
pinMode(kolLF,OUTPUT); 
pinMode(kolRB,OUTPUT); 
pinMode(kolRF,OUTPUT);  


speeed = 150;
rok = 2019;
mesiac = 1;
den = 1;
hod = 1;
minuti = 1;
myRTC.setDS1302Time(0, minuti, hod, 6, den, mesiac, rok);


Serial.println("Ako prvú vec musis nastavit cfg ");
Serial.println("Pre pomoc stlac H");
Serial.println("Pre poloautomaticku stalc C");
Serial.println("Pre defaultnu stalc E ");
}


void loop(){

switch(Serial.read()) 
 {
case 'S':cuvanie();  
break; 

case 'W':dopredu();  
break;

case 'A':lavo();  
break;

case 'D':pravo();  
break;

case 'B':sstop();  
break;

case 'H':help();  
break;

case 'N':rychclost();
break;

case 'C':autoconfig(); 
break;  

case 'E':defaul();
break;

 }
}




/*********************************************************************************
**                                                                              **
**                                Void (Core)                                   **
**                                                                              **
**                                                        Matej Mokrý           **
**********************************************************************************/

void autoconfig()    
    {
#include "autoconfig.h"
    }

void cuvanie()    
    {
     analogWrite(ENB,speeed);  
     analogWrite(ENA,speeed);
     digitalWrite(kolRB,LOW);  
     digitalWrite(kolLB,LOW);  
     digitalWrite(kolRF,HIGH);
     digitalWrite(kolLF,HIGH);   
    }

void lavo()        
    {
     analogWrite(ENB,speeed);  
     analogWrite(ENA,speeed);
     digitalWrite(kolLF,LOW); 
     digitalWrite(kolRB,LOW);  
     digitalWrite(kolRF,HIGH);
     digitalWrite(kolLB,HIGH);
    }

void pravo()         
    {
     analogWrite(ENB,speeed);  
     analogWrite(ENA,speeed);
     digitalWrite(kolRB,HIGH);
     digitalWrite(kolRF,LOW );   
     digitalWrite(kolLB,LOW);   
     digitalWrite(kolLF,HIGH);    
    }    

void dopredu()        
    {
     analogWrite(ENB,speeed);  
     analogWrite(ENA,speeed);
     digitalWrite(kolLB,HIGH);
     digitalWrite(kolRB,HIGH);      
     digitalWrite(kolRF,LOW);  
     digitalWrite(kolLF,LOW);       
    }

void sstop()        
    {
     analogWrite(ENB,speeed);  
     analogWrite(ENA,speeed);
     digitalWrite(kolRB,HIGH);
     digitalWrite(kolRF,HIGH);
     digitalWrite(kolLB,HIGH);
     digitalWrite(kolLF,HIGH);
    }

void help()
{
#include "help.h" 

}     

void defaul()
{

Serial.println("Zadal si defaultnu moznost");
speeed = 150;
rok = 2019;
mesiac = 1;
den = 1;
hod = 1;
minuti = 1;
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
            Serial.println("Vseko je nastavene teraz staci ist len na rpi3 na porte 1880 a ip 192.168.0.22 u mna doma :) ");


}    



void rychclost()   // Iba pre node-red
{

Serial.println("Zadaj rychlost");
while (Serial.available() == 0) {}
speeed = Serial.parseInt();
Serial.println(speeed);

}

