// SmartButton or another button library
 
#include "SmartButton.h"

SmartButton::SmartButton(uint8_t pin, uint32_t holdtime, bool pullup)
{
  _pin = pin;
  _pullup = pullup;
  _holdtime = holdtime;
  _debounce = false;
}

void SmartButton::begin()
{
	if (_pullup) pinMode(_pin, INPUT_PULLUP);
	else pinMode(_pin, INPUT);
    _currpinstate = !_pullup;
    _currbuttstate = RELEASED;
}

void SmartButton::update()
{
  bool newpinstate = digitalRead(_pin);
  if (!_pullup) newpinstate = !newpinstate;
  if (!_debounce && newpinstate != _currpinstate)
  {
  	_start_check = millis();
  	_debounce = true;
  	//Serial.println("Start Check");
  }
  if (millis() - _start_check > DEBOUNCE_TIME)
  {
  	if (newpinstate != _currpinstate)
  	{
  		bool changed = false;
  		if (_currbuttstate == PRESSED || _currbuttstate == HOLD && !changed)
	  	{
	  		_lastbuttupdate = millis();
	  		//Serial.println("Start Released");
	  		_currbuttstate = RELEASED;
	  		changed = true;
	  	}
  		if (_currbuttstate == RELEASED && !changed)
	  	{
	  		_lastbuttupdate = millis();
	  		//Serial.println("Start Pressed");
	  		_currbuttstate = PRESSED;
	  	}
  	}
  	_debounce = false;
  	_currpinstate = newpinstate;
  }
  if (millis() - _lastbuttupdate > _holdtime && _currbuttstate == PRESSED)
  {
  	//Serial.println("Start Hold");
  	_currbuttstate = HOLD;
  }
}

bool SmartButton::isReleased() const
{
	return _currbuttstate == RELEASED;
}

bool SmartButton::isHold() const
{
	return _currbuttstate == HOLD;
}

bool SmartButton::isPressed() const
{
	return _currbuttstate == PRESSED;
}
