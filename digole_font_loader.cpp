#include "application.h"

STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));
SYSTEM_THREAD(ENABLED);

#include "fonts.h"

#define FONT userfont1
#define SLOT 0
#define TEST "01234"

#define _Digole_Serial_UART_
#include "DigoleGeo.h"

DigoleSerialDisp display(&Serial1, 115200);

void setup() {
  display.begin();

  display.clearScreen();
  display.println(String::format("Uploading Font\r\nSize: %u bytes\r\nSlot: %i", sizeof(FONT), SLOT));

  delay(500);

  display.uploadUserFont(sizeof(FONT), FONT, SLOT);

  delay(1000);

  display.clearScreen();
  display.setFont(200 + SLOT);
  display.drawStr(0, 0, TEST);
  display.displayConfig(0);
}

void loop() {}
