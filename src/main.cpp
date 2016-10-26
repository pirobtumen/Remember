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
//  Remember
//
//  Simple command line task-manager.
//
// -----------------------------------------------------------------------------

#include <cstring>
#include <iostream>
#include <string>

#include "task.hpp"
#include "taskdb.hpp"
#include "tasker.hpp"

#include "cmd/command.hpp"
#include "cmd/cmdget.hpp"
#include "cmd/cmdadd.hpp"
#include "cmd/cmddel.hpp"
#include "cmd/cmdfinish.hpp"

// TODO: Improve
Command * parse_args(int args, char * argc[]){

  const std::string COMMAND_UNKNOWN_ERROR = "Unknown command.";
  Command * cmd;
  std::string cmd_name;
  std::string data;

  char add[] = "add";
  char del[] = "del";
  char finish[] = "finish";

  if(args > 2){

    // ADD TASK
    // -----------------------------------------------
    if( strcmp(argc[1],add) == 0 ){

      for(int i = 2; i < args; i++){
        data += argc[i];
        data += " ";
      }

      cmd = new CmdAdd(data);
    }

    // DELETE TASK
    // -----------------------------------------------
    else if( strcmp(argc[1],del) == 0 ){
      cmd = new CmdDel( std::atoi(argc[2]) );
    }

    // FINISH TASK
    // -----------------------------------------------
    else if( strcmp(argc[1],finish) == 0 ){
      cmd = new CmdFinish( std::atoi(argc[2]) );
    }

    // ERROR
    // -----------------------------------------------
    else{
      std::cout << COMMAND_UNKNOWN_ERROR << std::endl;
      exit(-1);
      // TODO: Show help.
    }

  }
  else{
    cmd = new CmdGet();
  }

  return cmd;
}

int main( int args, char ** argc ){

  Command * command;
  Tasker tasker;

  command = parse_args(args,argc);
  command->set_tasker(&tasker);

  command->execute();
  delete command;
}
