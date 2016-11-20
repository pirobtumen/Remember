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

#include "cmd/cmdshow.hpp"

// -----------------------------------------------------------------------------

CmdShow::CmdShow(int argc, char * argv[]){
  parse(argc,argv);
}

// -----------------------------------------------------------------------------

void CmdShow::execute(){
  Task task;
  unsigned int id;
  std::string finished;

  if(data.size() != 1){
    //ERR
  }
  else{
    id = std::stoi(data[0]);
    task = tasker -> get_task(id);

    finished = (task.is_finished()) ? "yes" : "no";

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "ID:       " << id << std::endl;
    std::cout << "Task:     " << task.get_task() << std::endl;
    std::cout << "Finished: " << finished << std::endl;
    std::cout << "Created:  " << task.get_created_date().to_str() << std::endl;

    if( !task.get_end_date().empty() )
      std::cout << "End date: " << task.get_end_date().to_str() << std::endl;
    else
      std::cout << "End date: no" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
  }



}

// -----------------------------------------------------------------------------
