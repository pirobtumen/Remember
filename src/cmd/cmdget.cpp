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

#include "cmd/cmdget.hpp"

// -----------------------------------------------------------------------------

CmdGet::CmdGet(){}

// -----------------------------------------------------------------------------

void CmdGet::execute() const{
  unsigned int count = 1;
  std::vector<Task> task_list;

  tasker -> get_task_list(task_list);

  std::cout << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "ID" << " | " << "Task" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;

  for(auto & task: task_list){

    if(task.is_finished()){
      std::cout << "\033[9m" << count << " - "  << task.get_task() << "\033[0m"<< std::endl;
    }
    else{
      std::cout << count << " | " << task.get_task() << std::endl;
    }
    count++;
  }
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << std::endl;
}

// -----------------------------------------------------------------------------
