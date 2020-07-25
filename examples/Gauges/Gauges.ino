/**
 * FT81x on ST7701S Arduino Driver
 *
 * MIT License
 *
 * Copyright (c) 2020 Raphael Stäbler
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#include "FT81x.h"

FT81x ft81x = FT81x(10, 9, 8, 7);

void setup() {
    SPI.begin();
    ft81x.begin();

    ft81x.setRotation(FT81x_ROTATE_LANDSCAPE);

    ft81x.beginDisplayList();
    ft81x.clear(FT81x_COLOR_RGB(0, 0, 0));

    ft81x.drawGauge(240, 160, 100, FT81x_COLOR_RGB(255, 255, 255), FT81x_COLOR_RGB(0, 100, 100), FT81x_OPT_NOPOINTER, 10, 5, 75, 100);
    ft81x.drawGauge(240, 160, 100, FT81x_COLOR_RGB(255, 100, 100), FT81x_COLOR_RGB(0, 0, 0), FT81x_OPT_NOBACK | FT81x_OPT_NOTICKS, 10, 5, 75, 100);

    ft81x.drawGauge(160, 320, 60, FT81x_COLOR_RGB(255, 255, 255), FT81x_COLOR_RGB(0, 150, 50), 0, 6, 5, 37, 100);
    ft81x.drawGauge(320, 320, 60, FT81x_COLOR_RGB(255, 255, 255), FT81x_COLOR_RGB(0, 50, 150), 0, 6, 5, 69, 100);

    ft81x.swapScreen();
}

void loop() {
    // do nothing
}
