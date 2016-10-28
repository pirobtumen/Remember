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
//
//  Remember
//
//  ============================================================================
//
//  Simple command line task-manager.
//
//  Alberto Sola - 2016
//
// -----------------------------------------------------------------------------

#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <utility>

#include "task.hpp"
#include "taskdb.hpp"
#include "tasker.hpp"

#include "cmd/command.hpp"
#include "cmd/cmdget.hpp"
#include "cmd/cmdadd.hpp"
#include "cmd/cmddel.hpp"
#include "cmd/cmdfinish.hpp"
#include "cmd/cmdshow.hpp"
#include "cmd/cmdhelp.hpp"

// -----------------------------------------------------------------------------

enum CmdType {GET, ADD, DELETE, FINISH, SHOW, HELP};

// -----------------------------------------------------------------------------

Command * parse_command(int argc, char * argv[]){
  /*
    Get the command and execute it.

    The "Command" object is the one that parses the options.
  */
  Command * cmd = nullptr;

  CmdType input = GET;

  std::map<std::string,CmdType> command_list;
  std::map<std::string,CmdType>::iterator found;

  // 1. Add Commands
  // ---------------------------------------------------------------------------

  command_list.insert(std::pair<const char*,CmdType>("add",CmdType::ADD));
  command_list.insert(std::pair<std::string,CmdType>("a",CmdType::ADD));

  command_list.insert(std::pair<const char*,CmdType>("delete",CmdType::DELETE));
  command_list.insert(std::pair<const char*,CmdType>("del",CmdType::DELETE));
  command_list.insert(std::pair<const char*,CmdType>("d",CmdType::DELETE));

  command_list.insert(std::pair<const char*,CmdType>("finish",CmdType::FINISH));
  command_list.insert(std::pair<const char*,CmdType>("f",CmdType::FINISH));

  command_list.insert(std::pair<const char*,CmdType>("show",CmdType::SHOW));
  command_list.insert(std::pair<const char*,CmdType>("s",CmdType::SHOW));

  command_list.insert(std::pair<const char*,CmdType>("get",CmdType::GET));
  command_list.insert(std::pair<const char*,CmdType>("g",CmdType::GET));

  command_list.insert(std::pair<const char*,CmdType>("help",CmdType::HELP));
  command_list.insert(std::pair<const char*,CmdType>("h",CmdType::HELP));
  // 2. Get CommandType
  // ---------------------------------------------------------------------------

  if(argc > 1){

    found = command_list.find(argv[1]);

    if( found != command_list.end() )
      input = (*found).second;

    else{
      std::cout << "Unknown command." << std::endl;
      input = HELP;
    }
  }

  // 3. Load Command and parse args
  // ---------------------------------------------------------------------------

  switch (input) {
    case ADD:
      cmd = new CmdAdd(argc,argv);
      break;

    case DELETE:
      cmd = new CmdDel(argc,argv);
      break;

    case FINISH:
      cmd = new CmdFinish(argc,argv);
      break;

    case GET:
      cmd = new CmdGet();
      break;

    case SHOW:
      cmd = new CmdShow(argc,argv);
      break;

    case HELP:
      cmd = new CmdHelp();
      break;

  }

  return cmd;
}

// -----------------------------------------------------------------------------

int main( int argc, char ** argv ){
  Command * command = nullptr;
  Tasker tasker;

  command = parse_command(argc,argv);
  command->set_tasker(&tasker);
  command->execute();

  delete command;
}
