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

#ifndef __COMMAND_HPP
#define __COMMAND_HPP

#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <iostream>
#include "tasker.hpp"

// -----------------------------------------------------------------------------

class Command{
protected:
  static Tasker * tasker;

  std::vector<std::string> data;
  std::map<std::string,bool> options;
  std::map<std::string,std::string> arguments;

  void  add_option(const char * opt);
  void  add_argument(const char * opt);

  bool  check_option(const char * opt) const;

  void  parse(int argc, char * argv[]);

public:
  Command();

  void set_tasker(Tasker * tasker) const;

  virtual void execute();
  virtual ~Command();
};

// -----------------------------------------------------------------------------

#endif
