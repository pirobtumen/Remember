# Remember

Fast and powerfull GUI and command line task manager.

![Remember](/screenshot/remember.png)

## Install

Now you have to compile it manually.

Dependencies:
- g++
- gtkmm30-devel

Build:

make

Run:

./bin/remember

You can copy the executable wherever you want, or maybe add it to the path.

Under linux you can run:
- make install

It copies the executable in /home/<user>/.local/bin.

In future versions it will support all the platforms.

## Features

- Basic GUI :)
- Add/Delete tasks.
- Finish/Start tasks.
- Finish date.
- Group tasks using **tags**.

## GUI Mode

Do you prefer use it in a graphic mode? No problem!

./remember gui

## Commands

### GUI

Commands: **gui**

Shows a basic GUI :)
In future versions it will be shown by default.

### Get

Commands: **get, g**

Action: show tasks.

Options:
- -a: show all.
- -f: show finished tasks only.
- -t tag: show tasks with 'tag'.

Usage: remember [get, g] [-f,-a]

### Add
Commands: **add, a**

Action: add a new task.

Argument:
- -f DD/MM/YY - End date.
- -t tag      - Task tag.

Usage: remember [add,a] [Task data] [-f DD/MM/YYYY]

### Delete
Commands: **delete, del, d**

Action: delete tasks.

Usage: remember [delete,del,d] <ID1 ID2...>

### Finish
Commands: **finish, f**

Action - Finished task: start task.
Action - Not finished task: finish task.

Usage: remember [finish,f] <ID1 ID2...>

### Show
Commands: **show, s**

Action: show task info.

Usage: remember [show, s] [ID]

### Help

Commands: **help, h**

Action: show help.

Usage: remember [show, s] [ID]

## To Do

Very long list :)
