# Remember

Fast and powerfull command line task manager.

## Features

- Add/Delete tasks.
- Finish/Start tasks.
- Finish date.
- Group tasks using **tags**.

## Commands

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
