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
  add_argument("-t"); // Tag

  parse(argc, argv);
}

// -----------------------------------------------------------------------------

void CmdAdd::execute(){
  // TODO: check if date is correct
  std::map<std::string,std::string>::const_iterator find;
  std::string finish_date = "-f";
  std::string tag = "-t";
  std::string task_data = "";
  Task task;

  // Error if empty

  for(auto & word: data)
    task_data += word + ' ';

  find = arguments.find(finish_date);
  if( find != arguments.end() && !find->second.empty()  )
    task.set_finish_date(Date(find->second));

  find = arguments.find(tag);
  if( find != arguments.end() && !find->second.empty()  )
    task.set_tag(find->second);

  task.set_task(task_data);

  // TODO: check if can be added
  tasker -> add_task(task);

  // TODO: check if can be saved
  tasker -> save();

  std::cout << "Task added." << std::endl;
}

// -----------------------------------------------------------------------------
