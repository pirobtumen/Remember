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

#include "cmd/command.hpp"

// -----------------------------------------------------------------------------

Tasker * Command::tasker = 0;

// -----------------------------------------------------------------------------

Command::Command(){}

// -----------------------------------------------------------------------------

void Command::add_option(const char * opt){
  options.insert(std::pair<const char *, bool>(opt,false));
}

// -----------------------------------------------------------------------------

bool Command::check_option(const char * opt) const{
  bool status = false;
  std::map<std::string,bool>::const_iterator find = options.find(opt);

  if( find != options.end()  )
    status = (*find).second;

  return status;
}

// -----------------------------------------------------------------------------

void Command::add_argument(const char * opt){
  arguments.insert(std::pair<const char *,std::string>(opt,std::string()));
}

// -----------------------------------------------------------------------------

std::string Command::get_argument(const char * opt) const{
  std::map<std::string,std::string>::const_iterator find = arguments.find(opt);
  std::string arg = "";

  if( find != arguments.end() )
    arg = (*find).second;

  return arg;
}

// -----------------------------------------------------------------------------

void Command::parse(int argc, char * argv[]){

  char c;

  bool arg = false;
  bool err = false;

  std::map<std::string,bool>::iterator opt_find;
  std::map<std::string,std::string>::iterator arg_find;

  for(int i = 2; i < argc && !err; i++ ){

    c = argv[i][0];

    if( c == '-' && !arg ){

      opt_find = options.find(argv[i]);

      if(opt_find != options.end())
        opt_find->second = true;

      else{
        arg_find = arguments.find(argv[i]);
        if( arg_find != arguments.end() )
          arg = true;

      }
    }

    else if( c == '-' && arg )
      err = true;

    else if(arg){
      arg_find->second = argv[i];
      arg = false;
    }

    else
      data.push_back(argv[i]);


  }

  // TODO: If error -> Show.

}

// -----------------------------------------------------------------------------

void Command::set_tasker(Tasker * new_tasker) const{
  tasker = new_tasker;
}

// -----------------------------------------------------------------------------

void Command::execute(){
  std::cout << "Something's wrong :)" << std::endl;
}

// -----------------------------------------------------------------------------

Command::~Command(){}

// -----------------------------------------------------------------------------
