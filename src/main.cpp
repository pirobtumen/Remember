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

enum CmdType {GET, ADD, DELETE, FINISH, ERROR, SHOW};

Command * parse_argc(int argc, char * argv[]){

  const std::string COMMAND_UNKNOWN_ERROR = "Unknown command.";
  Command * cmd = nullptr;
  CmdType input = ERROR;
  std::string cmd_name;
  std::string data;

  std::map<std::string,CmdType> command_list;
  std::map<std::string,CmdType>::iterator found;

  cmd_name = "add";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name,CmdType::ADD));
  cmd_name = "a";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name,CmdType::ADD));

  cmd_name = "delete";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name,CmdType::DELETE));
  cmd_name = "del";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name,CmdType::DELETE));
  cmd_name = "d";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name,CmdType::DELETE));

  cmd_name = "finish";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name, CmdType::FINISH));
  cmd_name = "f";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name, CmdType::FINISH));

  cmd_name = "show";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name, CmdType::SHOW));
  cmd_name = "s";
  command_list.insert(std::pair<std::string,CmdType>(cmd_name, CmdType::SHOW));

  if(argc == 1)
    input = GET;

  else if(argc > 2){

    found = command_list.find(argv[1]);

    if( found != command_list.end() )
      input = (*found).second;
    else
      input = ERROR;

  }

  switch (input) {
    case ADD:
      for(int i = 2; i < argc; i++){
        data += argv[i];
        data += " ";
      }
      cmd = new CmdAdd(data);
      break;

    case DELETE:
      cmd = new CmdDel( std::atoi(argv[2]) );
      break;

    case FINISH:
      cmd = new CmdFinish( std::atoi(argv[2]) );
      break;

    case GET:
      cmd = new CmdGet();
      break;

    case ERROR:
      std::cout << COMMAND_UNKNOWN_ERROR << std::endl;
      exit(-1);
      // TODO: Show help.
      break;

    case SHOW:
      cmd = new CmdShow( std::atoi(argv[2]) );
      break;
  }

  return cmd;
}

int main( int argc, char ** argv ){

  Command * command = nullptr;
  Tasker tasker;

  command = parse_argc(argc,argv);
  command->set_tasker(&tasker);

  command->execute();
  delete command;
}
