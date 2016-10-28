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

#include "cmd/cmdhelp.hpp"

// -----------------------------------------------------------------------------

CmdHelp::CmdHelp(){}

// -----------------------------------------------------------------------------

CmdHelp::CmdHelp(int argc, char * argv[]){
  parse(argc,argv);
}

// -----------------------------------------------------------------------------

void CmdHelp::execute() const{
  std::cout << "Remember help" << std::endl;
  std::cout << "==========================================================="<<std::endl;
  std::cout << "add,         a   [Task] [-f DD/MM/YYYY]   - Add a new task. -f: end date." << std::endl;
  std::cout << "get,         g                            - Show all tasks." << std::endl;
  std::cout << "show,        s   [Task ID]                - Show task info." << std::endl;
  std::cout << "finish,      f   <Task ID ...>            - Finish one or more tasks." << std::endl;
  std::cout << "delete, del, d   <Task ID ...>            - Delete one or more tasks." << std::endl;
}

// -----------------------------------------------------------------------------
