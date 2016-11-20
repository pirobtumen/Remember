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

CmdGet::CmdGet(int argc, char * argv[]){
  add_option("-f"); // Show finished only
  add_option("-a"); // Show all
  parse(argc,argv);
}

// -----------------------------------------------------------------------------

void CmdGet::execute(){
  bool show_finished = false;
  std::vector<Task> task_list;

  tasker -> get_task_list(task_list);

  std::cout << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "ID" << " | " << "Task" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;

  if(check_option("-f")){

    for(auto & task: task_list){

      if(task.is_finished())
        std::cout << task.get_id() << " | " << task.get_task() << std::endl;

    }

  }
  else{
    show_finished = check_option("-a");

    for(auto & task: task_list){

      if(!task.is_finished()){
        std::cout << task.get_id() << " | " << task.get_task() << std::endl;
      }
      else if(show_finished){
        std::cout << "\033[9m";
        std::cout << task.get_id() << " | " << task.get_task() << std::endl;
        std::cout << "\033[0m";
      }

    }

  }

  std::cout << "-------------------------------------------" << std::endl;
  std::cout << std::endl;
}

// -----------------------------------------------------------------------------
