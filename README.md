# WebUI

[![N|Solid](https://raw.githubusercontent.com/alifcommunity/webui/main/screenshot.png)](https://github.com/alifcommunity/webui)

[![Build Status](https://img.shields.io/github/issues/alifcommunity/webui.svg?branch=master)](https://github.com/alifcommunity/webui)

WebUI is a free and open source library that can help you using any installed web browser as your user interface. Basically you can transform an basic console app to a nice GUI application, in a easy way.

## Why WebUI?

First, web technologies is everywhere now, and web browsers today have everything a modern UI need, your application will look nicer, and won't need any external library to run.

## How its work?

Basically this library use latest web server and WebSocket standards to maintaine the communication in binary mode between the web browser and your application. You receive any click events, and of course you can send data or executing JavaScript code. 

## How I can use it?

- Include one header file:
```sh
#include <webui/webui.hpp>
```

- Set your HTML code
```sh
const std::string html = R"V0G0N(
<!DOCTYPE html>
<html>
	<head>
		<title>My first WebUI app</title>
	</head>
	<body>
		<h1>Welcome to WebUI!</h1>
		<button id="MyButtonID">Click on me!</button>
	</body>
</html>
)V0G0N";
```

- Create a window object
```sh
webui::window my_window(&html);
```

- Create your handler function
```sh
void my_handler(){

    std::cout << "You clicked on a button!" << std::endl;
}
```

- Bind your HTML element with your handler function
```sh
my_window.bind("MyButtonID", my_handler);
```

- Show the window!
```sh
my_window.show();
```

- Make infinit loop while window shown
```sh
std::thread ui(webui::loop);
ui.join();
```

You can also show the window using a specific web browser

```sh
if(!my_window.show(webui::browser::firefox))    // If Firefox not installed
    my_window.show();                           // try other web browsers.
```

## Complete examples

Please see examples folder.

## Features

- C++ 17 
- Lightweight and fast binary mode communication 
- One header file 
- Multiplatform & Multi Browser 
- Private user browser profiles 
- Customized app mode look & feel

## Status

| OS | Browser  | Status |
| ------ | ------ | ------ |
| Windows | Firefox | Supported |
| Windows | Chrome | Supported |
| Windows | Edge | Supported |
| Linux | Firefox | Supported |
| Linux | Chrome | Supported |
| macOS | Firefox | Under development |
| macOS | Chrome | Under development |
| macOS | Safari | Under development |

## How to use pre-compiled version ?

- Goto http://webui.me and download latest release WebUI library.

## How to clone

```sh
git clone https://github.com/alifcommunity/webui.git
```

## Build from source - Windows
- [ ! ] Boost 1.74 already embedded with this repository, no action needed.
- Windows SDK 10x. You can download it from http://microsoft.com 
- Microsoft Visual Studio build tools. basically goto Start -> Visual Studio 20xx -> Native Tools Command Prompt.
- CMake +3.1.0. You can download it from https://cmake.org/download

### Using MSVC (Recommended)
```sh
git clone https://github.com/alifcommunity/webui.git
cd webui
mkdir build
cd build
```

Generate Visual Studio 2017 solution.
```sh
cmake .. -G "Visual Studio 15 2017" -A Win32
```

Generate Visual Studio 2019 solution.
```sh
cmake .. -G "Visual Studio 16 2019" -A Win32
```

Generate Makefile for Microsoft Visual Studio build tools.
```sh
cmake .. -G "NMake Makefiles"
nmake
```

### Using MinGW (beta)

Generate Makefile for MinGW (beta)
```sh
cmake .. -G "MinGW Makefiles"
make
```

## Build from source - Linux
- C++17 compiler (GCC/Clang): ```sudo apt install build-essential```
- Boost lib +1.70.0: ```sudo apt install libboost-all-dev```
- CMake +3.1.0: ```sudo apt install cmake```

```sh
git clone https://github.com/alifcommunity/webui.git
cd webui
mkdir build
cd build
cmake ..
make
```

## Build from source - macOS
- Clang
- [!] Comming soon!

### License

GNU General Public License v3.0
