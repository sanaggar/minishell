# Minishell

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Norm-42-00babc?style=for-the-badge" alt="42"/>
  <img src="https://img.shields.io/badge/Shell-Bash-green?style=for-the-badge&logo=gnubash" alt="Bash"/>
</p>

<p align="center">
  <strong>A Unix shell implementation from scratch in C</strong><br>
  Recreating core bash functionalities: parsing, pipes, redirections, and process management
</p>

---

## Features

### Built-in Commands
| Command | Description |
|---------|-------------|
| `echo` | Display text with `-n` flag support |
| `cd` | Navigate directories (`cd`, `cd -`, `cd <path>`) |
| `pwd` | Print current working directory |
| `export` | Set and display environment variables |
| `unset` | Remove environment variables |
| `env` | Display the current environment |
| `exit` | Exit the shell with optional status code |

### Shell Capabilities
- **Pipes** (`|`) -- chain commands, connecting stdout to stdin
- **Input redirection** (`<`) -- read from file
- **Output redirection** (`>`) -- write to file (truncate)
- **Append redirection** (`>>`) -- write to file (append)
- **Heredoc** (`<<`) -- read input until delimiter
- **Environment variables** -- expand `$VAR` and `$?` (last exit status)
- **Quote handling** -- single quotes (literal) and double quotes (with expansion)
- **Signal handling** -- `Ctrl+C`, `Ctrl+\`, `Ctrl+D` behave like in bash
- **Syntax error detection** -- informative error messages for invalid input
- **Exit status** -- proper status codes (0, 1, 2, 126, 127, 130, 131)

---

## Architecture

```
minishell_42/
├── main.c                  # Shell loop (readline prompt)
├── minishell.h             # Structs & prototypes
├── get_next_line*.c        # Line reader (used for heredoc)
├── parser/                 # Input analysis & tokenization
│   ├── parser.c            #   Entry point: clean input, remove quotes
│   ├── parser_delegator.c  #   Route to pipe / variable / semicolon handlers
│   ├── parser_variable*.c  #   $VAR and $? expansion
│   ├── parser_redir*.c     #   Redirection processing (< > >> <<)
│   ├── parser_error*.c     #   Syntax validation
│   ├── input_split*.c      #   Argument tokenization
│   └── handle_basic*.c     #   Dispatch to builtins or exec
├── builtins/               # Built-in command implementations
│   ├── echo.c
│   ├── cd.c / cd_utils.c
│   ├── pwd.c
│   ├── export.c / export_utils.c
│   ├── unset.c
│   ├── env.c
│   ├── exit.c / exit_utils.c
│   ├── exec.c / exec_utils.c  # External command execution (fork/execve)
│   ├── pipe.c              # Pipe mechanics (pipe/fork/dup2)
│   └── signal*.c           # SIGINT / SIGQUIT handling
├── libft/                  # Custom C library (40+ functions)
└── Makefile
```

### Execution Flow

```
readline() ──> Parser ──> Delegator ──> Handler
                 │            │
                 │            ├── Variable expansion ($VAR, $?)
                 │            ├── Pipe detection & splitting
                 │            └── Semicolon splitting
                 │
                 └── Tokenizer ──> Redirection setup ──> Command dispatch
                                                              │
                                              ┌───────────────┼───────────────┐
                                           Builtin        fork + execve    Pipe chain
```

---

## Getting Started

### Prerequisites

- GCC compiler
- GNU Readline library
- Make

```bash
# Debian / Ubuntu
sudo apt-get install libreadline-dev

# macOS
brew install readline
```

### Build & Run

```bash
git clone https://github.com/sanaggar/minishell_42.git
cd minishell_42
make
./minishell
```

---

## Usage Examples

```bash
minishell$ echo "Hello, World!"
Hello, World!

minishell$ ls -la | grep ".c" | wc -l
5

minishell$ cat < input.txt > output.txt

minishell$ export NAME="minishell"
minishell$ echo "This is $NAME"
This is minishell

minishell$ echo $?
0

minishell$ cat << EOF
> line 1
> line 2
> EOF
line 1
line 2

minishell$ cd /tmp && pwd
/tmp

minishell$ exit 42
```

---

## Technical Highlights

- **Zero memory leaks** -- validated with extensive testing (`valgrind`)
- **Custom C library** -- 40+ reimplemented standard functions (`libft`)
- **Robust parsing** -- handles nested quotes, escaped characters, and edge cases
- **Process management** -- proper use of `fork()`, `execve()`, `pipe()`, `dup2()`, `waitpid()`
- **Signal safety** -- single global variable for async-signal-safe communication
- **Norminette compliant** -- follows 42's strict coding standard

---

## What I Learned

- Deep understanding of **Unix process model** (fork/exec, file descriptors, pipes)
- Building a **recursive descent parser** for shell grammar
- Managing **inter-process communication** through pipes and signals
- Handling **complex string parsing** with multiple quoting rules
- Writing **leak-free C code** with proper resource cleanup
- Working as a team under 42's peer-evaluation system

---

## Author

**sanaggar** -- 42 Nice
**hbigourd** -- 42 Nice
