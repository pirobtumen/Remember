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

#include "cmd/cmdadd.hpp"

// -----------------------------------------------------------------------------

CmdAdd::CmdAdd(int argc, char * argv[]){

  add_argument("-f"); // Finish date

  parse(argc, argv);
}

// -----------------------------------------------------------------------------

void CmdAdd::execute() const{
  // TODO: check if date is correct
  std::map<std::string,std::string>::const_iterator find;
  std::string end_date = "-f";
  std::string task_data = "";
  Task task;

  // Error if empty

  for(auto & word: data)
    task_data += word + ' ';

  find = arguments.find(end_date);
  if( find != arguments.end() )
    task.set_end_date(Date(find->second));

  task.set_task(task_data);

  tasker -> add_task(task);
  tasker -> save();

  std::cout << "Task added." << std::endl;
}

// -----------------------------------------------------------------------------
