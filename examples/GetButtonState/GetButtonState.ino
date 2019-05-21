#include <SmartButton.h>

// создаём объект для работы с кнопкой с параметром номер пина
SmartButton button(7, 1000);
// Библиотека не использует delay
// также есть два необзятельных параметра:
// время длительного зажатия кнопки: по умолчанию 2000 мc
// выбор подтяжки кнопки: по умолчанию подтяжка к "+"
// TroykaButton button(7, 1000, true);

void setup() {
  // открываем монитор Serial порта
  Serial.begin(9600);
  // начало работы с кнопкой
  button.begin();
}

void loop() 
{
  // считываем данные с кнопки
  button.update();
  // опеределяем клик кнопки
  if (button.isPressed()) {
    Serial.println("Key on press");
  }
  // определяем отжатие кнопки
  if (button.isReleased()) {
    Serial.println("Key is release");
  }
  // определяем длительное зажатие кнопки
  if (button.isHold()) {
    Serial.println("Key on long press");
  }
}
