#pragma once

class Adafruit_SSD1306;

class Display
{
  private:
    Adafruit_SSD1306* display;

  public:
    Display();
    void printSingleDose();
    void printDoubleDose();
    void printTime(double time);
    void printText(char text[]);
    void clear();
    void printStatistics(int numberSingles, int numberDoubles);
};