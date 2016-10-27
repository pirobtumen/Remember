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

#include "date.hpp"
#include <iostream>

// -----------------------------------------------------------------------------

Date::Date(){
  separator = '/';
  set_date(0,0,0);
}

// -----------------------------------------------------------------------------

void Date::set_date(short int iday, short int imonth, int iyear){
  day = iday;
  month = imonth;
  year = iyear;
}

// -----------------------------------------------------------------------------

short int Date::get_day() const{ return day; }

// -----------------------------------------------------------------------------

short int Date::get_month() const{ return month; }

// -----------------------------------------------------------------------------

int Date::get_year() const{ return year; }

// -----------------------------------------------------------------------------

void Date::set_day(short int iday){ day = iday; }

// -----------------------------------------------------------------------------

void Date::set_month(short int imonth){ month = imonth; }

// -----------------------------------------------------------------------------

void Date::set_year(int iyear){ year = iyear; }

// -----------------------------------------------------------------------------

void Date::set_current(){
  const int BASE_YEAR = 1900;
  std::time_t time_ = std::time(nullptr);
  std::tm * current_time = std::localtime(&time_);

  day = current_time->tm_mday;
  month = current_time->tm_mon;
  year = BASE_YEAR + current_time->tm_year;

}

// -----------------------------------------------------------------------------

void Date::set_from_str(const std::string & date){
  //TODO: improve

  std::vector<std::string> date_parts;
  std::string word = "";

  for( auto c: date ){

    if( c == separator ){
      date_parts.push_back(word);
      word = "";
    }
    else
      word += c;

  }

  date_parts.push_back(word);

  day = std::stoi(date_parts[0]);
  month = std::stoi(date_parts[1]);
  year = std::stoi(date_parts[2]);

}

// -----------------------------------------------------------------------------

std::string Date::to_str() const{
  std::string date = "";

  date += std::to_string(day);
  date += separator;
  date += std::to_string(month);
  date += separator;
  date += std::to_string(year);

  return date;
}

// -----------------------------------------------------------------------------

Date & Date::operator=(const Date & date){
  day = date.day;
  month = date.month;
  year = date.year;

  return (*this);
}

// -----------------------------------------------------------------------------
