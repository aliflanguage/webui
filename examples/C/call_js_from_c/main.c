// Call JavaScript from C Example

#include "webui.h"

void my_function_exit(webui_event_t* e) {

    // Close all opened windows
    webui_exit();
}

void my_function_count(webui_event_t* e) {

    // This function gets called every time the user clicks on "MyButton1"

    // Create a buffer to hold the response
    char response[64];

    // Run JavaScript
    if(!webui_script(e->window, "return GetCount();", 0, response, 64)) {

        printf("JavaScript Error: %s\n", response);
        return;
    }

    // Get the count
    int count = atoi(response);

    // Increment
    count++;

    // Generate a JavaScript
    char js[64];
    sprintf(js, "SetCount(%d);", count);

    // Run JavaScript (Quick Way)
    webui_run(e->window, js);
}

int main() {

    // HTML
    const char* my_html = "<!DOCTYPE html>"
    "<html>"
    "  <head>"
    "    <title>Call JavaScript from C Example</title>"
    "    <style>"
    "      body {"
    "        background: linear-gradient(to left, #36265a, #654da9);"
    "        color: AliceBlue;"
    "        font: 16px sans-serif;"
    "        text-align: center;"
    "        margin-top: 30px;"
    "      }"
    "      button {"
    "        margin: 5px 0 10px;"
    "      }"
    "    </style>"
    "  </head>"
    "  <body>"
    "    <h1>WebUI - Call JavaScript from C</h1>"
    "    <br>"
    "    <button id=\"MyButton1\">Count <span id=\"count\">0</span>!</button>"
    "    <br>"
    "    <button id=\"MyButton2\">Exit</button>"
    "    <script>"
    "      let count = 0;"
    "      function GetCount() {"
    "        return count;"
    "      }"
    "      function SetCount(number) {"
    "        document.getElementById('count').innerHTML = number;"
    "        count = number;"
    "      }"
    "    </script>"
    "  </body>"
    "</html>";

    // Create a window
    size_t my_window = webui_new_window();

    // Bind HTML elements with C functions
    webui_bind(my_window, "MyButton1", my_function_count);
    webui_bind(my_window, "MyButton2", my_function_exit);

    // Show the window
    webui_show(my_window, my_html); // webui_show_browser(my_window, my_html, Chrome);

    // Wait until all windows get closed
    webui_wait();

    return 0;
}

#if defined(_MSC_VER)
    int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
        return main();
    }
#endif
