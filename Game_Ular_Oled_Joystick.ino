#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define RIGHT 1
#define UP    2
#define LEFT  3
#define DOWN  4

const int D_NORTH = LEFT;
const int D_EAST = UP;
const int D_SOUTH = RIGHT;
const int D_WEST = DOWN;

int xPin = A0;
int yPin = A1;
int xPosition = 0;
int yPosition = 0;

long score = 0;

byte snakePixelX[20];
byte snakePixelY[20];

int snakeX = 10;
int snakeY = 30;
int snakeLength = 1;
volatile int snakeDir = D_NORTH;
volatile int buttonState = LOW;

int minX = 0;
int minY = 20;
int maxX = 128;
int maxY = 64;

int foodX = 0;
int foodY = 0;

const int BUTTON_PIN = 7;

void setupButton() {
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), debounceChangeDirection, CHANGE);
}

long debouncing_time = 15; //Debouncing Time in Milliseconds
volatile unsigned long last_micros;

void debounceChangeDirection() {
  if ((long)(micros() - last_micros) >= debouncing_time * 1000) {
    changeDirection();
    last_micros = micros();
  }
}

int read_key()
{
  int key_temp;
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  //  buttonState = digitalRead(buttonPin);

  if (yPosition < 410) { //Serial.print("UP");
    key_temp = UP;
    return key_temp;

  }
  if (yPosition > 490) { //Serial.print("DOWN");
    key_temp = DOWN;
    return key_temp;

  }
  if (xPosition < 410) { //Serial.print("LEFT");
    key_temp = LEFT;
    return key_temp;
  }
  if (xPosition > 490) { //Serial.print("RIGHT");
    key_temp = RIGHT;
    return key_temp;
  }

}
void changeDirection() {

  switch (read_key()) {
    case D_NORTH:
      snakeDir = D_EAST;
      break;
    case D_EAST:
      snakeDir = D_SOUTH;
      break;
    case D_SOUTH:
      snakeDir = D_WEST;
      break;
    case D_WEST:
      snakeDir = D_NORTH;
      break;
  }

  buttonState = !buttonState;
}

void setupScreen()   {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  display.clearDisplay();

  minX = 0;
  minY = 8;
  maxX = display.width() - 1;
  maxY = display.height() - 1;

  renderScore();
}

void setup()   {
  Serial.begin(9600);
  setupButton();
  setupScreen();

  dropFood();

  digitalWrite(BUTTON_PIN, buttonState);
}

bool outOfBounds() {
  return snakeX <= minX || snakeY <= minY || snakeX >= maxX || snakeY >= maxY;
}

void gameOver() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("   Anda  ");
  display.println("  Kalah!!   ");
  display.println("    :(");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(" YouTube/");
  display.println("  Belajar ");
  display.println("   Robot ");
  
  display.display();

  score = 0;
  snakeLength = 1;
  snakeX = display.width() / 2;
  snakeY = display.height() / 2;

  snakePixelX[snakeLength - 1] = snakeX;
  snakePixelY[snakeLength - 1] = snakeY;

  snakeDir = D_SOUTH;

  delay(2000);

  display.clearDisplay();
  renderScore();
}

// Drop food on random location
void dropFood() {
  foodX = random(minX + 1, maxX - 1);
  foodY = random(minY + 1, maxY - 1);
}

bool collectFood() {
  if (snakeX == foodX && snakeY == foodY) {
    score += 10;

    tone(8, 500, 200);
    tone(8, 2250, 250);
    tone(8, 150, 100);
    tone(8, 1500, 100);

    renderScore();
    dropFood();

    return true;
  } else {
    return false;
  }
}

void renderScore() {
  display.fillRect(0, 0, display.width() - 1, 8, BLACK);
  display.fillRect(0, 0, 128, 8, WHITE);
  display.setTextSize(1);
  display.setTextColor(INVERSE);
  display.setCursor(0, 0);

  display.print(" Skor Ular: ");
  display.print(String(score, DEC));
  


  // TOP
  display.drawLine(0, 8, display.width() - 1, 8, WHITE);
  // LEFT
  display.drawLine(0, 8, 0, display.height() - 1, WHITE);
  // RIGHT
  display.drawLine(display.width() - 1, 8, display.width() - 1, display.height() - 1, WHITE);
  // BOTTOM
  display.drawLine(0, display.height() - 1, display.width() - 1, display.height() - 1, WHITE);
}

bool crashedIntoSelf() {
  for (byte i = 10; i < snakeLength; i++) {
    if (snakeX == snakePixelX[i] && snakeY == snakePixelY[i]) {
      return true;
    }
  }

  return false;
}

void drawScreen() {
  bool foodCollected = false;

  // Clear the buffer.
  display.clearDisplay();
  display.fillCircle(foodX, foodY, 2, WHITE);
  //display.drawPixel(foodX, foodY, WHITE);
  foodCollected  = collectFood();

  // Check snake position
  if (outOfBounds() || crashedIntoSelf()) {
    gameOver();
  }

  // Render the snake
  for (int i = 0; i < snakeLength; i++) {
    display.fillCircle(snakePixelX[i], snakePixelY[i], 2, WHITE);
    //display.drawPixel(snakePixelX[i], snakePixelY[i], WHITE);
  }

  // Move pixel values
  for (int i = snakeLength; i > 0; i--) {
    snakePixelX[i] = snakePixelX[i - 1];
    snakePixelY[i] = snakePixelY[i - 1];
  }

  if (foodCollected) {
    snakeLength += 1;
    snakePixelX[snakeLength - 1] = snakeX;
    snakePixelY[snakeLength - 1] = snakeY;
  }

  switch (read_key()) {
    case D_NORTH:
      snakeY -= 1;
      break;
    case D_EAST:
      snakeX += 1;
      break;
    case D_SOUTH:
      snakeY += 1;
      break;
    case D_WEST:
      snakeX -= 1;
      break;
  }

  snakePixelX[0] = snakeX;
  snakePixelY[0] = snakeY;

  renderScore();
  display.display();
}

void loop() {

  drawScreen();

}
