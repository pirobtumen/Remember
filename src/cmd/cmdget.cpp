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
  add_option("-f");     // Show finished only
  add_option("-a");     // Show all
  add_argument("-t");   // Tag
  parse(argc,argv);
}

// -----------------------------------------------------------------------------

void CmdGet::print_task(const Task & task) const{
  std::cout << task.get_id() << " | " << task.get_tag() << " | " << task.get_task() << std::endl;
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
  Date finish_date;
  std::vector<Task> task_list;
  std::string tag_arg = get_argument("-t");

  // Get tasks
  if( tag_arg.empty() )
    tasker -> get_task_list(task_list);
  else
    tasker -> get_task_list(task_list,get_argument("-t"));

  // Get current date
  today_date.set_current();

  // Show header
  std::cout << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "ID" << " | " << "Tag" << " | " << "Task" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;

  // Print finished tasks
  if(check_option("-f")){

    for(auto & task: task_list){

      if(task.is_finished())
        print_task(task);

    }

  }
  else{
    // Check "all" option
    show_finished = check_option("-a");

    // Print tasks
    for(auto & task: task_list){

      if(!task.is_finished()){

        finish_date = task.get_finish_date();

        // Text: bold green
        if(finish_date == today_date)
          std::cout << "\033[32;1m";
        // Text: bold red
        else if(!finish_date.empty() && finish_date < today_date)
          std::cout << "\033[31;1m";

        print_task(task);
      }
      else if(show_finished){
        std::cout << "\033[9m";
        print_task(task);
      }

      // Clear text effects
      std::cout << "\033[0m";

    }

  }

  std::cout << "-------------------------------------------" << std::endl;
  std::cout << std::endl;
}

// -----------------------------------------------------------------------------
