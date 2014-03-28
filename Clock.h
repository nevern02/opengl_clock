#ifndef __CLOCK_H_INCLUDED__
#define __CLOCK_H_INCLUDED__

#include <cmath>
#include <cstring>
#include <sstream>

#include <GL/glut.h>
#include <GL/freeglut.h>

class Clock
{
  public:
    Clock(int x, int y, float radius);

  private:
    static const double PI;
    const int x, y;
    const float radius;
    void draw() const;
    void drawCircle(float color[3], float lineWidth, int lineType, float radius) const;
    void drawHand(float angle, float color[3], float lineWidth) const;
    void drawNumbers(float color[3], void* font) const;
};

#endif
