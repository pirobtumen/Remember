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

#ifndef __TASK_HPP
#define __TASK_HPP

#include <string>
#include <map>
#include <iostream>

#include "date.hpp"

// -----------------------------------------------------------------------------

class Task{
private:
  unsigned int id;
  bool finished;
  std::string data;
  Date creation_date;
  Date finish_date;
  std::string tag;

  void                    set_status(const std::string & status);

public:
  Task();
  Task( const std::string & new_data );

  void                    load_from_str( const std::string & task_data );
  std::string             to_str() const;

  const std::string &     get_task() const;
  const Date &            get_creation_date() const;
  const Date &            get_finish_date() const;
  unsigned int            get_id() const;
  const std::string &     get_tag() const;

  void                    set_task(const std::string & task);
  void                    set_creation_date(const Date & date);
  void                    set_finish_date(const Date & date);
  void                    set_id(unsigned int new_id);
  void                    set_tag(const std::string & new_tag);

  bool                    finish();
  bool                    finish(bool status);

  bool                    is_finished() const;
  bool                    is_empty() const ;


};

// -----------------------------------------------------------------------------

#endif
