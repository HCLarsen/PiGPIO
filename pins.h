/* This array matches the Rasberry Pi pin numbers (the array index) to the 
   BCM2835 pin numbers. This way, the users can use the Raspberry Pi numbers
   and the software can easily convert it to something it can use. */

uint8_t pins[41] ;

void mapPins() {
  pins[0] = 0;
  pins[1] = 0;
  pins[1] = 0;
  pins[2] = 0;
  pins[3] = 2;
  pins[4] = 0;
  pins[5] = 3;
  pins[6] = 0;
  pins[7] = 4;
  pins[8] = 14;
  pins[9] = 0;
  pins[10] = 15;
  pins[11] = 17;
  pins[12] = 18;
  pins[13] = 27;
  pins[14] = 0;
  pins[15] = 22;
  pins[16] = 23;
  pins[17] = 0;
  pins[18] = 24;
  pins[19] = 10;
  pins[20] = 0;
  pins[21] = 9;
  pins[22] = 25;
  pins[23] = 11;
  pins[24] = 8;
  pins[25] = 0;
  pins[26] = 7;
  pins[27] = 0;
  pins[28] = 0;
  pins[29] = 5;
  pins[30] = 0;
  pins[31] = 6;
  pins[32] = 12;
  pins[33] = 13;
  pins[34] = 0;
  pins[35] = 19;
  pins[36] = 16;
  pins[37] = 26;
  pins[38] = 20;
  pins[39] = 0;
  pins[40] = 21;
};
