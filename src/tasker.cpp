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

#include "tasker.hpp"

// -----------------------------------------------------------------------------

Tasker::Tasker(){

  task_db.set_name("task.txt");
  task_db.read();

}

// -----------------------------------------------------------------------------

void Tasker::add_task(const Task & task){
  task_db.add_task(task);
}

// -----------------------------------------------------------------------------

const Task & Tasker::get_task(unsigned int id) const{
  return task_db.get_task(id);
}

// -----------------------------------------------------------------------------

const std::vector<Task> & Tasker::get_task_list(){
  return task_db.get_task_list();
}

// -----------------------------------------------------------------------------

void Tasker::delete_task(unsigned int id){

  // TODO: check size
  // TODO: return value
  if( id > 0 )
    task_db.delete_task(id);

}

// -----------------------------------------------------------------------------

void Tasker::save() const{
  task_db.save();
}

// -----------------------------------------------------------------------------

bool Tasker::finish_task(unsigned int id){
  return task_db.finish_task(id);
}

// -----------------------------------------------------------------------------
