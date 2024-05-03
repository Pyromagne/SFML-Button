////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2024 Pyromagne
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #define RESET_COLOR "\x1B[0m"
#endif
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
#ifndef COLORESCAPE_HPP
    #define COLORESCAPE_HPP

    #include <iostream>
    #include <string>
    #include <windows.h>

    void enable_vtp(void);

    namespace ce
    {
        enum Color
        {
            Red = 160,
            Orange = 208,
            Yellow = 220,
            Green = 28,
            Blue = 27,
            Purple = 127,
            White = 255,
            Black = 0,
        };

        void setForegroundColor(int);
        void setBackgroundColor(int);
        void reset(void);
        std::string colorIn(int, std::string);
        std::string colorIn2(int, int, std::string);
    }
#endif
////////////////////////////////////////////////////////////

