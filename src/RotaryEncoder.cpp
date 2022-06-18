#include <RotaryEncoder.h>
#include <Definitions.h>
#include <Encoder.h>
#include <JC_Button.h>

bool clicked = true;

RotaryEncoder::RotaryEncoder() {
    button = new Button(ENC_SW, 100, true, true);
    encoder = new Encoder(ENC_CLK, ENC_DT);
    button->begin();
}

bool RotaryEncoder::wasTurnedRight() {
    if (encoder->read() < 0 - ENC_TOL) {
        encoder->write(0);
        return true;
    }
    return false;
}

bool RotaryEncoder::wasTurnedLeft() {
    if (encoder->read() > 0 + ENC_TOL) {
        encoder->write(0);
        return true;
    }
    return false;
}

bool RotaryEncoder::isPressed() {
    button->read();
    if (button->isPressed()) {
        return true;
    }
    return false;
}

bool RotaryEncoder::isSingleClicked() {
    button->read();
    
    if (button->isPressed() && clicked == false) {
        // run this only once
        clicked = true;
        return true;
    }

    if (button->isReleased() && clicked == true) {
        // reset clicked on button up
        clicked = false;
    }

    return false;
}

bool RotaryEncoder::isReleased() {
    button->read();
    if (button->isReleased()) {
        return true;
    }
    return false;
}

bool RotaryEncoder::wasPressed() {
    if (!wasLongPressed() && button->isPressed()) {
        return true;
    }
    return false;
}

bool RotaryEncoder::wasLongPressed() {
    button->read();
    if (button->pressedFor(ENC_SW_LONG_PRESS_DUR)) {
        return true;
    }
    return false;
}