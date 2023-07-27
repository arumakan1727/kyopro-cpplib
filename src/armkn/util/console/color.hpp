#pragma once

namespace armkn::console::color {

const char *BLACK, *RED, *GREEN, *YELLOW, *BLUE, *MAGENTA, *CYAN, *WHITE;
const char *DIM, *RESET;

__attribute__((constructor)) void enable_color() {
  BLACK = "\x1b[30;1m";
  RED = "\x1b[31;1m";
  GREEN = "\x1b[32;1m";
  YELLOW = "\x1b[33;1m";
  BLUE = "\x1b[34;1m";
  MAGENTA = "\x1b[35;1m";
  CYAN = "\x1b[36;1m";
  WHITE = "\x1b[37;1m";
  DIM = "\x1b[;2m";
  RESET = "\x1b[;m";
}

void disable_color() {
  BLACK = "";
  RED = "";
  GREEN = "";
  YELLOW = "";
  BLUE = "";
  MAGENTA = "";
  CYAN = "";
  WHITE = "";
  DIM = "";
  RESET = "";
}

}  // namespace armkn::console::color
