#include <CircularBuffer.h>
CircularBuffer<int, 128> buffer;

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  int anu2 = map(analogRead(A0), 0, 1023, 0, 255 );
  analogWrite(6, anu2);
  
  int anu = map(analogRead(A0), 0, 1023, 0, 63 );
  buffer.push(anu);
  if (buffer.isEmpty()) {
    Serial.println("empty");
  } else {
    for (decltype(buffer)::index_t i = 0; i <= buffer.size() - 1; i++) {
       //display.drawLine(10+(i*2), 32, 10+(i*2), 60-buffer[i], WHITE);
       //display.drawLine(0+(i), 32, 0+(i), 63-buffer[i], WHITE);
      display.drawPixel(0 + (i), 63 - buffer[i], WHITE);

    }
    display.fillRoundRect(0, 0, 20, 10,1, WHITE);
    display.setTextSize(1);
    display.setTextColor(INVERSE);
    display.setCursor(2, 2);
    display.println(anu2);
    display.display();

  }
  //delay(1);
}
