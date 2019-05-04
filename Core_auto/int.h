/**************************************************
**                                              **
**                pin pomenovanie               **
**                                              **
**************************************************/

//control board 
int kolLB=2;
int kolLF=4;
int kolRB=7;
int kolRF=8;
int ENA=5;
int ENB=10;


//clock 
virtuabotixRTC myRTC(13, 3, 1); //1=RST 3=DATE  13=CLOCK

//auto speed 
int speeed;
//cas
int rok;
int mesiac;
int den;
int hod;
int minuti;


