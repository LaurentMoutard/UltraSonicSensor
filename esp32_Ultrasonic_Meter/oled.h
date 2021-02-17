#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


char buffer [50];

//const char *convert_int(int myInt) {
//  static char buf[6];
//  strcpy(buf, u8g2_u8toa( (uint8_t)(myInt/10), 3));
//  buf[3] =  '.';
//  buf[4] = (myInt % 10) + '0';
//  buf[5] = '\0';
//  return buf;
//}

void oledPrint(long val1){
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_cupcakemetoyourleader_tr);  // choose a suitable font
  u8g2.drawStr(0,12, "Distance : ");  // write something to the internal memory
  u8g2.drawStr(90,12, ltoa(val1, buffer, 10));  // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
}
