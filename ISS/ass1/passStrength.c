#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int getPassStrength(char *pass) {
  int strength = 0;
  int len = strlen(pass);
  int type[4] = {0};
  int iii;
  char c;
  if (len > 7) {
    strength++;
    for (iii = 0; iii < len; iii++) {
      c = pass[iii];
      if (c == ' ' || c == '\t' || c == '\n') {
        return -1;
      } else if (isdigit(c)) {
        type[0] = 1;
      } else if (islower(c)) {
        type[1] = 1;
      } else if (isupper(c)) {
        type[2] = 1;
      } else {
        type[3] = 1;
      }
    }
  }
  for (iii = 0; iii < 4; iii++) {
    strength += type[iii];
  }
  return strength;
}

int main(int argc, char const *argv[]) {
  char *pass;
  pass = getpass("Enter password: ");
  int st;
  while ((st = getPassStrength(pass)) < 5) {
    if (st < 0) {
      pass =
          getpass("Error: spaces and tabs not allowed.\nRe-enter password: ");
      continue;
    }
    if (st == 0) {
      pass = getpass("Error: Too short!\nRe-enter password: ");
    } else {
      pass = getpass(
          "Error: Password must contain a capital letter, lower case letter, a number and a special symbol\n \
							Re-enter password:");
    }
  }
  printf("Password successfully set: %s\n", pass);
  return 0;
}