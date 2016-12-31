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

#include "gui/rememberview.hpp"

// -----------------------------------------------------------------------------

RememberView::RememberView(Tasker * tasker){
  // Set the 'Tasker' Object
  // TODO: check if null
  this -> tasker = tasker;

  // Initialize the view
  init();
}

// -----------------------------------------------------------------------------

void RememberView::init(){
  // Window basic properties
  set_title("Remember");
  set_default_size(400, 500);
  set_position(Gtk::WindowPosition::WIN_POS_CENTER);

  //
  TaskItem::set_tasker(tasker);

  // Load widgets
  create_header_bar();
  create_task_list();

  // Load tasks
  load_tasks();

  // Show window
  show_all_children(true);
}

// -----------------------------------------------------------------------------

void RememberView::on_button_add_clicked(){
  /*
    Create Task dialog and add a task.
  */
  int response;
  Task task;
  TaskDialog dialog("New task", (*this));

  // Show dialog
  response = dialog.run();

  // "OK"
  if( response == Gtk::ResponseType::RESPONSE_OK ){

    // Get data
    task.set_task(dialog.get_task());
    task.set_tag(dialog.get_tag());

    // Set data
    tasker -> add_task(task);
    tasker -> save();

    // Update view
    task_list.push_back(task);
    listbox.add(task_list.back());
    task_list.back().show_all();
  }

}

// -----------------------------------------------------------------------------

void RememberView::row_clicked(Gtk::ListBoxRow* row){
  int response;
  Task task = tasker -> get_task(((TaskItem *)row) -> get_task_id());
  TaskView task_view(task,"Task", (*this));

  response = task_view.run();

  // OK
  if( response == Gtk::ResponseType::RESPONSE_OK ){

    // Get data
    task.set_task(task_view.get_task());
    task.set_tag(task_view.get_tag());

    // Set data
    tasker -> update_task(task);
    tasker -> save();

    // Update view
    ((TaskItem *)row) -> load_task_with_tag(task);
  }

}

// -----------------------------------------------------------------------------

void RememberView::create_header_bar(){
  /*
    Create the custom title bar.
  */

  Glib::RefPtr< Gtk::StyleContext > style_context;

  // Set tittle
  header_bar.set_title("Remember");

  // Close button
  header_bar.set_show_close_button();

  // Create menu
  mi_group_tag.set_label("Group by tag");
  mi_group_tag.set_sensitive(false);
  mi_show_finished.set_label("Show finished tasks");
  mi_show_finished.set_sensitive(false);
  menu.append(mi_show_finished);
  menu.append(mi_group_tag);

  // Config button
  menu_bttn.set_image_from_icon_name("document-properties");
  menu_bttn.set_menu(menu);

  // Add button
  add_task.set_label("Add");

  // Callback -> Signal "clicked"
  add_task.signal_clicked().connect(sigc::mem_fun( *this,
    &RememberView::on_button_add_clicked));

  // Some default style
  style_context = add_task.get_style_context();
  style_context -> add_class("suggested-action");

  // Add the buttons
  header_bar.pack_start(add_task);
  header_bar.pack_end(menu_bttn);

  // Set the header bar
  set_titlebar(header_bar);
  menu.show_all();

}

// -----------------------------------------------------------------------------
void RememberView::load_tasks(){
  /*
    Load a list of tasks.
  */

  std::vector<Task> taskdb;
  TaskItem task_item;

  // Get tasks from the model
  tasker -> get_task_list(taskdb);

  // Add the tasks
  for(const auto & task: taskdb){
    task_item.load_task_with_tag(task);
    task_list.push_back(task_item);
    listbox.add(task_list.back());
  }

}

// -----------------------------------------------------------------------------

void RememberView::create_task_list(){
  /*
    Set ScrolledWindow and Listbox.
  */
  // Scrolled Window properties
  scrolled_window.set_policy(Gtk::PolicyType::POLICY_NEVER,
                             Gtk::PolicyType::POLICY_AUTOMATIC);
  scrolled_window.add(listbox);

  // ListBox properties
  listbox.set_selection_mode(Gtk::SelectionMode::SELECTION_NONE);
  listbox.signal_row_activated().connect(sigc::mem_fun( *this, &RememberView::row_clicked));

  // Add to the main window
  add(scrolled_window);
}

// -----------------------------------------------------------------------------
