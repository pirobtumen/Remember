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
  /*
    Show tasks.
    Default: not finished tasks.
    -a: show all tasks.
    -f: show finished tasks.

    If a task end date is today, the color is bold green.
  */
  bool show_finished = false;
  Date today_date;
  Date end_date;
  std::vector<Task> task_list;

  // Get tasks
  tasker -> get_task_list(task_list);

  // Get current date
  today_date.set_current();

  // Show header
  std::cout << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "ID" << " | " << "Task" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;

  // Print finished tasks
  if(check_option("-f")){

    for(auto & task: task_list){

      if(task.is_finished())
        std::cout << task.get_id() << " | " << task.get_task() << std::endl;

    }

  }
  else{
    // Check "all" option
    show_finished = check_option("-a");

    // Print tasks
    for(auto & task: task_list){

      if(!task.is_finished()){

        end_date = task.get_end_date();

        // Text: bold green
        if(end_date == today_date)
          std::cout << "\033[32;1m";
        // Text: bold red
        else if(!end_date.empty() && end_date < today_date)
          std::cout << "\033[31;1m";

        std::cout << task.get_id() << " | " << task.get_task() << std::endl;
      }
      else if(show_finished){
        std::cout << "\033[9m";
        std::cout << task.get_id() << " | " << task.get_task() << std::endl;
      }

      // Clear text effects
      std::cout << "\033[0m";

    }

  }

  std::cout << "-------------------------------------------" << std::endl;
  std::cout << std::endl;
}

// -----------------------------------------------------------------------------
