#include <ESP32-RGB64x32MatrixPanel-I2S-DMA.h>

RGB64x32MatrixPanel_I2S_DMA     display;      // RGB Panel

const byte row0 = 2+0*10;
const byte row1 = 2+1*10;
const byte row2 = 2+2*10;


void setup() 
{
 
  // put your setup code here, to run once:
  delay(1000); Serial.begin(115200); delay(200);

  Serial.println("...Starting Display");
  display.begin();  // setup the display with no double buffering
  display.setTextColor(display.color565(128, 128, 128));  

  
  // Buffer 0 test
  display.fillScreen(display.color565(128, 0, 0));  
  display.setCursor(3, row0);
  display.print(F("Buffer 0"));
  display.setCursor(3, row1);
  display.print(F(" Buffer 0"));
  Serial.println("Wrote to to Buffer 0");
  display.showDMABuffer(); 
  delay(1500);
  
  // Buffer 1 test
  display.flipDMABuffer();
  display.fillScreen(display.color565(0, 128, 0)); // shouldn't see this
  display.setCursor(3, row0);
  display.print(F("Buffer 1"));
  display.setCursor(3, row2);
  display.print(F(" Buffer 1"));
 
  Serial.println("Wrote to to Buffer 1");
  display.showDMABuffer();  
  delay(1500);
  /*
  delay(500);  
  display.fillScreen(display.color565(0, 0, 128));  
  delay(1000);
  display.flipDMABuffer();   
  delay(1000);   

  display.flipDMABuffer();
  */

}

void loop() {
  
  // Flip the back buffer
  display.flipDMABuffer();

  // Write: Set bottow row to black
  for (int y=20;y<MATRIX_HEIGHT; y++)
  for (int x=0;x<MATRIX_WIDTH; x++)
  {
    display.drawPixelRGB888( x, y, 0, 0, 0);
  }

  // Write:  Set bottom row to blue (this is what should show)
  for (int y=20;y<MATRIX_HEIGHT; y++)
  for (int x=0;x<MATRIX_WIDTH; x++)
  {
    display.drawPixelRGB888( x, y, 0, 0, 64);
  }

  // Now show this back buffer
  display.showDMABuffer();  
  delay(1000);

  // Flip back buffer
  display.flipDMABuffer();   

  // Show this buffer
  display.showDMABuffer();   
  delay(1000);
/*
  //Parola.flushBufferAll

  // UpdateBackground
  for (int y=20;y<MATRIX_HEIGHT; y++)
  for (int x=0;x<MATRIX_WIDTH; x++)
  {
    //Serial.printf("\r\nFlushing x, y coord %d, %d", x, y);
    display.drawPixelRGB888( x, y, 0, 128, 0);
  }

    
  for (int y=20;y<MATRIX_HEIGHT; y++)
  for (int x=0;x<MATRIX_WIDTH; x++)
  {
    //Serial.printf("\r\nFlushing x, y coord %d, %d", x, y);
    display.drawPixelRGB888( x, y, 64, 0, 0);
  }
 // display.refreshDMAOutput();

   //display.flipDMABuffer();
     delay(20);
     display.showDMABuffer();  

*/
  

}
