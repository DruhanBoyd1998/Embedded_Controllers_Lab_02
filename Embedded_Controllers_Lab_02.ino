#include <Keypad.h>

#define ROW_NUM 4
#define COLUMN_NUM 4
#define PIN_X 10
#define PIN_Y 11
#define PIN_Z 12

char Last_Key_Press;

char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }

};

byte Row_Pin[ROW_NUM] = { 2, 3, 4, 5 };
byte Column_Pin[COLUMN_NUM] = { 6, 7, 8, 9 };

Keypad keypad = Keypad(makeKeymap(keys), Row_Pin, Column_Pin, ROW_NUM, COLUMN_NUM);

void setup() {

  Serial.begin(9600);
}

void loop() {

  char Key_Press = keypad.getKey();

  if (Key_Press) {
    Last_Key_Press = Key_Press;
    Serial.println(Key_Press);
  }

  switch (Last_Key_Press) {

    case ('0'):
      pinMode(PIN_X, INPUT);
      pinMode(PIN_Y, INPUT);
      pinMode(PIN_Z, INPUT);

      delay(1);
      break;

    case ('1'):
      pinMode(PIN_X, OUTPUT);
      pinMode(PIN_Y, OUTPUT);
      pinMode(PIN_Z, INPUT);

      digitalWrite(PIN_X, HIGH);
      digitalWrite(PIN_Y, LOW);
      delay(1);
      break;

    case ('2'):
      pinMode(PIN_X, OUTPUT);
      pinMode(PIN_Y, OUTPUT);
      pinMode(PIN_Z, INPUT);

      digitalWrite(PIN_X, LOW);
      digitalWrite(PIN_Y, HIGH);
      delay(1);
      break;

    case ('3'):
      pinMode(PIN_X, OUTPUT);
      pinMode(PIN_Y, OUTPUT);
      pinMode(PIN_Z, INPUT);

      digitalWrite(PIN_X, HIGH);
      digitalWrite(PIN_Y, LOW);
      delay(1);
      digitalWrite(PIN_X, LOW);
      digitalWrite(PIN_Y, HIGH);
      delay(1);
      break;

    case ('4'):
      pinMode(PIN_X, INPUT);
      pinMode(PIN_Y, OUTPUT);
      pinMode(PIN_Z, OUTPUT);

      digitalWrite(PIN_Y, HIGH);
      digitalWrite(PIN_Z, LOW);
      delay(1);
      break;

    case ('5'):
      pinMode(PIN_X, OUTPUT);
      pinMode(PIN_Y, OUTPUT);
      pinMode(PIN_Z, INPUT);

      digitalWrite(PIN_X, HIGH);
      digitalWrite(PIN_Y, LOW);
      delay(1);

      pinMode(PIN_X, INPUT);
      pinMode(PIN_Y, OUTPUT);
      pinMode(PIN_Z, OUTPUT);

      digitalWrite(PIN_Y, HIGH);
      digitalWrite(PIN_Z, LOW);
      delay(1);
      break;
  }
}
