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

#include "task.hpp"

// -----------------------------------------------------------------------------

Task::Task()
:data(""), deleted(false)
{}

// -----------------------------------------------------------------------------

Task::Task( const std::string & data )
:deleted(false)
{
  set_data(data);
}

// -----------------------------------------------------------------------------

void Task::set_data( const std::string & new_data ){
  data = new_data;
}

// -----------------------------------------------------------------------------

const std::string & Task::get_data() const{
  return data;
}

// -----------------------------------------------------------------------------

const std::string & Task::to_str() const{
  return data;
}

// -----------------------------------------------------------------------------

bool Task::is_deleted() const{
  return deleted;
}

// -----------------------------------------------------------------------------

void Task::mark_deleted(){
  deleted = true;
}

// -----------------------------------------------------------------------------
