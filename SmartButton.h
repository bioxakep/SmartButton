/****************************************************************************/
//  Function:       Header file for SmartButton
//  Arduino IDE:    Arduino-1.8.5
//  Author:         BioXaKeP
//  Date:           19/05/2019
//  Version:        v1.0
/****************************************************************************/

#ifndef _SMARTBUTTON_H_
#define _SMARTBUTTON_H_

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define DEBOUNCE_TIME   15
#define PRESSED 0x01
#define HOLD 0x02
#define RELEASED 0x03

class SmartButton
{
public:
    SmartButton(uint8_t pin, uint32_t holdtime = 1000, bool pullup = false);
    // инициализация кнопки
    void begin();
    // считывание данных с кнопки
    void update();
    // определение клика кнопки
    bool isPressed() const;
    // определение отжатие кнопки
    bool isReleased() const;
    // определение зажатие кнопки (по умолчанию 2 секунды)
    bool isHold() const;
private:
    // номера пина
    uint8_t _pin;
    // текущее состояние пина кнопки
    bool _currpinstate;
    // время длительного зажатия кнопки
    uint32_t _holdtime;
    // выбор подтяжки
    bool _pullup;
    // состояние кнопки
    uint8_t _currbuttstate;
    // время нажатия кнопки
    uint32_t _lastbuttupdate;
    // время начала задержки перед проверкой после дребезгов
    uint32_t _start_check;
    // ожидание окончания дребезгов
    bool _debounce;
};

#endif