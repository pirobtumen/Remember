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

#include "taskdb.hpp"

// -----------------------------------------------------------------------------

TaskDB::TaskDB(){}

// -----------------------------------------------------------------------------

TaskDB::TaskDB(const std::string & name){
  set_name(name);
}

// -----------------------------------------------------------------------------

void TaskDB::set_name(const std::string & name){
  db_file_name = name;
}

// -----------------------------------------------------------------------------

void TaskDB::read(){
  std::ifstream file(db_file_name, std::ofstream::in );
  std::string line;

  if( file.is_open() ){

    std::getline(file,line);

    while(!file.eof()){

      task_list.push_back(Task(line));
      std::getline(file,line);

    }
  }

  file.close();
}

// -----------------------------------------------------------------------------

void TaskDB::save() const{
  /*
    Save not deleted tasks, and moves finished to the end of the file.
  */
  std::ofstream file(db_file_name, std::ofstream::out | std::ofstream::trunc);
  std::vector<Task> finished;

  for( auto & task : task_list ){

    if(!task.is_deleted()){
      if(!task.is_finished())
        file << task.to_str() << std::endl;

      else
        finished.push_back(task);
    }

  }

  for( auto & task : finished )
    file << task.to_str() << std::endl;

  file.close();

}

// -----------------------------------------------------------------------------

void TaskDB::add_task( const Task & task ){
  task_list.push_back(task);
}

// -----------------------------------------------------------------------------

// Prec: id > 0
const Task & TaskDB::get_task( unsigned int id ) const{
  return task_list[id-1];
}

// -----------------------------------------------------------------------------

// Prec: id > 0
void TaskDB::delete_task(unsigned int id){
  task_list[id-1].mark_deleted();
}

// -----------------------------------------------------------------------------

void TaskDB::finish_task(unsigned int id){
  task_list[id-1].finish();
}

// -----------------------------------------------------------------------------

const std::vector<Task> & TaskDB::get_task_list() const{
  return task_list;
}

// -----------------------------------------------------------------------------
