# About this project.

## tdlm (Todo List Maker)
tdlm is a simple command line tool to parse source code and generate a todo list. Is written in C++ and Qt (5.5.1). The target platform is Linux, but tdlm should work on other OS:s to.

### Key features.
* [x] recursive file search.
* [x] parsing doxygen-styled todo tags for c++ and java.
* [x] support different output formats.
  * [x] generate a todolist as raw text, compatible with [kate-todo](https://github.com/fpersson/kate-todo).
  * [x] Markdown
  * [x] Plain text
* [x] write to file.
* [x] generate a todo list for stdout.
* [ ] configurable todo parser.

### Optional features.
These features will be implemented if i have time left.
* [x] Gist todo list for github.

### How to build
This project **require Qt 5.2** or later.

To build tdlm, import tdlm.pro to qtcreator. If you want to build the unittest import UnitTest.pro.

### Usage.
```
Usage: ./tdlm [options]
tdlm, ToDo List Maker.

Options:
  -v, --version             Displays version information.
  -h, --help                Displays this help.
  -d, --dir <dirname>       dir path ( /path/to/files/ )
  -f, --format <style>      Output format, valid options: txt todotxt, markdown
  -o, --output <outputfile>  outputfile ( /path/to/output | gist)
```

### Export todo to gist.
To export your todo list to github you need a oauth-token. The path to your token need to be *$HOME/.tdlm/oauth*

* [oauth]{https://help.github.com/articles/creating-an-access-token-for-command-line-use/}

## GaSiProMo (Galactic Side Project Month).

### Wtf is GaSiProMo?
*If you've wanted to make something fun, Nov's the time! Inspired by NaNoWriMo for writers, GaSiProMo is a group of programmers and hackers committed to finishing a side project in November. Join us!*

Read more at [GaSiProMo](https://codelympics.io/projects/3)

### Change log

#### 151115 Gist support.
* Added support for github gist
  * NOTE: This will only save your todo as a new gist, not update existing one.

#### 151109 Basic working edition.
* Improved output.
  * can save to file.
  * output to stdout.
* Most basic task works.

#### 151107 First working edition.
* The most basic functions is implemented (don't save to file yet).
* unittests for core classes.
  * Text format.
  * Todo parser.
* No unittest for reused code.
  * Filereader.
  * Filelister.

#### 151031 Init commit.
* Updated README.md with a short project description

## Feedback or questions.
* [reddit](https://www.reddit.com/r/codelympics/comments/3r28jc/tdlm_todo_list_maker/)
* [issue tracker](https://github.com/fpersson/GaSiProMo/issues)

### Credits
* Uffe Nordholm; for the name tdlm (naming _is_ the hardest thing to do).
