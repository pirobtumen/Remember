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
  Task task;
  unsigned int id = task.get_id();

  if( file.is_open() ){

    std::getline(file,line);

    while(!file.eof()){
      task.load_from_str(line);
      //task_list.insert(std::make_pair(id,task));

      //if(id > last_id)
      //  last_id = id;
      add_task(task);
      std::getline(file,line);
    }

  }

  file.close();
}

// -----------------------------------------------------------------------------

void TaskDB::save() const{
  /*
    Save all tasks.
  */
  std::ofstream file(db_file_name, std::ofstream::out | std::ofstream::trunc);

  for( auto & task : task_list )
        file << task.second.to_str() << std::endl;

  file.close();

}

// -----------------------------------------------------------------------------

void TaskDB::add_task( const Task & task ){
  last_id += 1;
  task_list.insert(std::make_pair(last_id, task));
}

// -----------------------------------------------------------------------------

// TODO: return reference -> keep an empty task.
Task TaskDB::get_task( unsigned int id ) const{
  std::map<unsigned int,Task>::const_iterator it = task_list.find(id);
  Task task;

  if( it != task_list.end() )
    task = (*it).second;

  return task;
}

// -----------------------------------------------------------------------------

void TaskDB::delete_task(unsigned int id){
  task_list.erase(id);
}

// -----------------------------------------------------------------------------

bool TaskDB::finish_task(unsigned int id){
  std::map<unsigned int,Task>::iterator it = task_list.find(id);
  bool status = false;

  if( it != task_list.end() )
    status = (*it).second.finish();

  return status;
}

// -----------------------------------------------------------------------------

void TaskDB::get_task_list(std::vector<Task> & tasks) const{
  for(auto & t : task_list)
    tasks.push_back(t.second);
}

// -----------------------------------------------------------------------------
