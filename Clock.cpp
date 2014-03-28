#include "Clock.h"

const double Clock::PI = 3.1415927;

Clock::Clock(int x, int y, float radius) : x(x), y(y), radius(radius)
{
  draw();
}

void Clock::draw() const
{
  float colorRed[3] = {1.0, 0.0, 0.0};
  float colorWhite[3] = {1.0, 1.0, 1.0};
  float colorBlack[3] = {0.0, 0.0, 0.0};
  const time_t now = time(0);
  tm *convertedTime = localtime(&now);
  int hours = convertedTime->tm_hour % 12;
  int minutes = convertedTime->tm_min;
  float hourAngles = 90 - (hours + minutes / 60.0) * (360 / 12);
  float minuteAngles = 90 - minutes * (360 / 60);

  // Draw clock border
  drawCircle(colorRed, 10.0, GL_LINE_LOOP, radius);

  // Draw clock face
  drawCircle(colorWhite, 1.0, GL_TRIANGLE_FAN, radius * 0.97);

  // Draw clock numbers
  drawNumbers(colorBlack, GLUT_BITMAP_TIMES_ROMAN_24);

  // Draw hour hand
  drawHand(hourAngles, colorBlack, 10.0);

  // Draw minute hand
  drawHand(minuteAngles, colorBlack, 3.5);
}

void Clock::drawCircle(float color[3], float lineWidth, int lineType, float radius) const
{
  GLfloat twicePI = 2.0f * PI;

  glColor3fv(color);
  glLineWidth(lineWidth);

  glBegin(lineType);
  for (int i = 0; i < 360; i += 5) {
    glVertex2f(
        x + (radius * cos(i * twicePI / 360)),
        y + (radius * sin(i * twicePI / 360))
        );
  }
  glEnd();
}

void Clock::drawNumbers(float color[3], void* font) const
{
  glColor3fv(color);

  for (int i = 3; i < 15; i++) {
    glRasterPos2f(
        x + (0.9 * radius * cos(i * 2 * PI / 12)),
        y + (0.9 * radius * sin(i * 2 * PI / 12))
        );
    std::stringstream ss;
    ss << 15 - i;
    char* cstr = new char [ss.str().length() + 1];
    std::strcpy(cstr, ss.str().c_str());
    glutBitmapString(font, (const unsigned char*)cstr);
  }
}

void Clock::drawHand(float angle, float color[3], float lineWidth) const
{
  glColor3fv(color);
  glLineWidth(lineWidth);

  glBegin(GL_LINES);
  glVertex2i(x, y);
  glVertex2i(
      x + (0.8 * radius * cos(angle * PI / 180)),
      y + (0.8 * radius * sin(angle * PI / 180))
      );
  glEnd();
}
