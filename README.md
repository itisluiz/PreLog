
# PreLog
![my machine badge](https://forthebadge.com/images/badges/works-on-my-machine.svg)

The `prelog`, as in preliminary logging, library contains the minimum foundations needed for setting up a debugging environment.

## Methods

### `prelog::msgBox`

Shows a Win32 message box with the given variadic provided arguments built as a stringstream.

**Usage:**
```cpp
#include <prelog/msgbox.hh>

int value = 42;

// Shows a message box titled "Message box title" with message "Value is 5"
int result = prelog::msgBox(MB_OK, "Message box title", "Value is ", value);
```

### `prelog::debugOut`
Outputs the provided variable arguments built as string to a tool such as [DebugView](https://learn.microsoft.com/pt-br/sysinternals/downloads/debugview).

**Usage:**
```cpp
#include <prelog/debugout.hh>

int value = 42;

// Writes a debug line to listeners such as DebugView or Visual Studio
int result = prelog::debugOut("Value is ", value, " at line ", __LINE__);
```

### `prelog::assertConsole` and `prelog::releaseConsole`
Makes sure that a console is available and properly redirected (or create one and redirect one if there isn't), or drop redirections freeing the console, respectively.

**Usage:**
```cpp
#include <prelog/console.hh>
#include <iostream>

// Allocate a console if there isn't any and redirect everything to it
prelog::assertConsole();
std::cout << "Hello, world!" "\n";
std::cin.get();

// Free the console and redirection files
prelog::releaseConsole();
```
