

#include <unistd.h>      // sleep, usleep, getopt
#include <stdlib.h>      // exit
#include "ssd1306_i2c.h" // LCD_Display, ssd1306_begin

int main(int argc, char **argv)
{
  unsigned short int count = 0;

  ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS); // LCD Screen initialization
  usleep(150000);                                           // Short delay to ensure the normal response of the lower functions

  int opt;
  while ((opt = getopt(argc, argv, "c")) != -1)
  {
    switch (opt)
    {
    case 'c': // clean screen and exit
      OLED_Clear();
      exit(0);
    }
  }
  LCD_DisplayInit();

  // Loop forever
  for (;;)
  {
    LCD_DisplayTemperature();

    sleep(1);
    count++;
    if (count > 0)
    {
      count = 0;
    }
  }
}
