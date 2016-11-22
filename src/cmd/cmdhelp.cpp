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

void CmdHelp::execute(){
  std::cout << "Remember help" << std::endl;
  std::cout << "==========================================================="<<std::endl;
  std::cout << "add,         a   [Task]                   - Add a new task." << std::endl;
  std::cout << "               -f  [DD/MM/YYYY]             · End date." << std::endl;
  std::cout << "               -t  [tag]                    · Set tag." << std::endl;
  std::cout << std::endl;
  std::cout << "get,         g                            - Show not finished tasks." << std::endl;
  std::cout << "               -f                           · Show finished tasks only." << std::endl;
  std::cout << "               -a                           · Show all." << std::endl;
  std::cout << "               -t                           · Filter by tag." << std::endl;
  std::cout << std::endl;
  std::cout << "show,        s   [ID]                     - Show task info." << std::endl;
  std::cout << "finish,      f   <ID1 ID2 ...>            - Finish/Start one or more tasks." << std::endl;
  std::cout << "delete, del, d   <ID1 ID2 ...>            - Delete one or more tasks." << std::endl;
  std::cout << "help,        h                            - Show help." << std::endl;
}

// -----------------------------------------------------------------------------
