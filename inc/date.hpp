// -----------------------------------------------------------------------------
//
// MIT License
//
// Copyright (c) 2016 Alberto Sola
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
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

#ifndef __DATE_HPP
#define __DATE_HPP

#include <ctime>
#include <string>
#include <vector>

// -----------------------------------------------------------------------------

class Date{
private:
  char separator;

  short int  day;
  short int  month;
  int        year;

public:
                  Date();

  void            set_date(short int day, short int month, int year);
  void            set_current();

  short int       get_day() const;
  short int       get_month() const;
  int             get_year() const;

  void            set_day(short int iday);
  void            set_month(short int imonth);
  void            set_year(int year);

  void            set_from_str(const std::string & date);
  std::string     to_str() const;

  Date &          operator=(const Date & date);
};

// -----------------------------------------------------------------------------

#endif
