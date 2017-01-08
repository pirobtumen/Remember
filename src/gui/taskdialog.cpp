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

#include "gui/taskdialog.hpp"

// -----------------------------------------------------------------------------

TaskDialog::TaskDialog(const std::string & title, Gtk::Window & parent)
: Gtk::Dialog(title,parent){

  load_view();

  set_actions();

  show_all_children();
}

// -----------------------------------------------------------------------------

void TaskDialog::load_view(){

  task_view.attach(txt_task,0,0,1,1);
  task_view.attach(task,1,0,1,1);
  task_view.attach(txt_tag,0,1,1,1);
  task_view.attach(tag,1,1,1,1);

  txt_task.set_label("Task: ");
  txt_tag.set_label("Tag: ");

  // TODO: margin with CSS
  task.set_margin_bottom(5);
  tag.set_margin_bottom(5);

  get_content_area() -> pack_start(task_view);

}

// -----------------------------------------------------------------------------

void TaskDialog::set_actions(){
  add_action_widget(cancel_button, Gtk::ResponseType::RESPONSE_CANCEL);
  add_action_widget(ok_button, Gtk::ResponseType::RESPONSE_OK);

  ok_button.set_label("OK");
  ok_button.get_style_context() -> add_class("suggested-action");

  cancel_button.set_label("Cancel");
}

// -----------------------------------------------------------------------------

Task TaskDialog::get_task(){
  Task dialog_task;

  // TODO: set creation date.
  dialog_task.set_task(task.get_text());
  // TODO: if empty -> General
  dialog_task.set_tag(tag.get_text());

  return dialog_task;
}

// -----------------------------------------------------------------------------

void TaskDialog::set_task(const Task & itask){
  task.set_text(itask.get_task());
  tag.set_text(itask.get_tag());
}

// -----------------------------------------------------------------------------
