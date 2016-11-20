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
{
  data = "";
  finished = false;
  id = 0;
  created_date.set_current();
}

// -----------------------------------------------------------------------------

Task::Task( const std::string & new_data )
{
  load_from_str(new_data);
}

// -----------------------------------------------------------------------------

// TODO: use a map to fill the data
void Task::load_from_str( const std::string & task_data ){
  std::vector<std::string> data_split;
  std::string tmp = "";
  char next_char;
  unsigned int data_size = task_data.size();

  for( unsigned int i = 0; i < data_size; i++ ){

    next_char = task_data[i];

    if(next_char == ','){

      data_split.push_back(tmp);
      tmp = "";

    }
    else
      tmp += next_char;

  }

  data_split.push_back(tmp);

  if(data_split.size() >= 1 )
    data = data_split[0];

  if( data_split.size() >= 2 && data_split[1][0] == '1' )
    finished = true;
  else
    finished = false;

  if( data_split.size() >= 3 )
    created_date.set_from_str(data_split[2]);

  if( data_split.size() >= 4 )
    end_date.set_from_str(data_split[3]);

  if( data_split.size() >= 5 )
    id = std::stoi(data_split[4]);
}

// -----------------------------------------------------------------------------

void Task::set_task(const std::string & task){
  data = task;
}
// -----------------------------------------------------------------------------

const std::string & Task::get_task() const{
  return data;
}

// -----------------------------------------------------------------------------

std::string Task::to_str() const{
  const char separator = ',';

  char char_finished = (finished)? '1' : '0';
  std::string task_data = data;

  task_data += separator;
  task_data += char_finished;
  task_data += separator;
  task_data += created_date.to_str();
  task_data += separator;
  task_data += end_date.to_str();
  task_data += separator;
  task_data += std::to_string(id);

  return task_data;
}

// -----------------------------------------------------------------------------

void Task::set_id(unsigned int new_id){
  id = new_id;
}

// -----------------------------------------------------------------------------

unsigned int Task::get_id() const{
  return id;
}

// -----------------------------------------------------------------------------

bool Task::is_empty() const{
  return id == 0;
}

// -----------------------------------------------------------------------------

bool Task::is_finished() const{
  return finished;
}

// -----------------------------------------------------------------------------

bool Task::finish(){
  bool last_value = finished;
  finished = !finished;
  return last_value;
}

// -----------------------------------------------------------------------------

const Date & Task::get_created_date() const{
  return created_date;
}

// -----------------------------------------------------------------------------

const Date & Task::get_end_date() const{
  return end_date;
}

// -----------------------------------------------------------------------------

void Task::set_end_date(const Date & date){
  end_date = date;
}

// -----------------------------------------------------------------------------
