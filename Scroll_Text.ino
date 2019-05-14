#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT);
  digitalWrite(4, HIGH);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer
  display.clearDisplay();
}

void loop() {
  if (digitalRead(4) == LOW) {
    display.invertDisplay(true);

  }
  else {
    display.invertDisplay(false);
  }
  //gambarTitik();
  menu();

}


void gambarTitik(void) {

  int x = analogRead(A6);
  x = map(x, 0, 1023, 0, 128);

  int y = analogRead(A7);
  y = map(y, 0, 1023, 0, 64);

  display.clearDisplay();
  display.setCursor(0, 0);

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.println(x);
  display.println(y);

  display.drawPixel(x, y, WHITE);
  display.drawCircle(x, y, 3, WHITE);

  display.display();

  delay(10);
}

void menu()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("Jancok!!!"));
  display.display();
  delay(2000);
}
