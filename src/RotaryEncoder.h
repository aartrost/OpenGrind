#pragma once

class Button;
class Encoder;

class RotaryEncoder
{
  private:
    Button *button;
    Encoder *encoder;
    bool clicked;
  
  public:
    RotaryEncoder();
    bool wasTurnedLeft();
    bool wasTurnedRight();
    bool isPressed();
    bool isSingleClicked();
    bool isReleased();
    bool wasPressed();
    bool wasLongPressed();
};