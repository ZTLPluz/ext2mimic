//
// Created by 23170 on 2022/5/24.
//

#include "../include/utils.h"

/*
 * Type in password without display
 *  #Not for direct call
 */
string _getPasswd() {
  fflush(stdin);
  string str;
  int i = 0;
  char ch;
  while ((ch = _getch()) != 13) {
    if (ch == '\b') {
      //cout<<"\b \b";
      if (str.length() != 0) {
        str.pop_back();
      }
      continue;
    }
    if (ch == ' ') {
      continue;
    }
    str += ch;
    //cout<<"*";
  }
  return str;
}

/*
 * Input regular text
 * #Not for direct call
 */
string _getRegular() {
  fflush(stdin);
  string str;
  cin >> str;
  return str;
}

/*
 * Input function with length limit, and overlength warning.
 * #Not for direct call
 */
string _getLine(int maxNum, string(*func)()) {

  while (true) {
    string temp = func();
    if (temp.length() > maxNum) {
      cout << endl << "Too Long. Must under " << maxNum << "words" << endl;
      continue;
    } else {
      return temp;
    }
  }
}

/*
 * Input password with Validation process.
 */
string getPasswdConfirm(int maxNum) {
  string passwd, passwdAgain;
  while (true) {
    passwd = _getLine(maxNum, _getPasswd);
    cout << endl << "Type again, please." << endl;
    fflush(stdout);
    passwdAgain = _getLine(maxNum, _getPasswd);
    if (passwd != passwdAgain) {
      cout << endl << "Two passwords are different. Try again from the first. " << endl;
      fflush(stdout);
      continue;
    } else {
      return passwd;
    }
  }
}
/*
 * Input regular text
 */
string getRegular(int maxNum) {
  return _getLine(maxNum, _getRegular);
}

/*
 * Input password without Validation process.
 */
string getPasswd(int maxNum) {
  return _getLine(maxNum, _getPasswd);
}

/*
 * Convert dir_name '/home/#username#/' to '~'
 */
string convertCurDir(char *dir, char *parse) {
  string temp_dir = dir;
  string temp_user_dir = parse;

  int length = temp_user_dir.length();
  if (temp_dir == temp_user_dir) {
    return "~";
  }
  if (temp_dir.substr(0, length) == temp_user_dir) {
    return "~" + temp_dir.substr(length);
  }
  return temp_dir;
}
/*
 * If input dir start with '~',
 * convert '~' to '/home/#username#/'
 */
string parseDir(const char *dir, char *parse) {
  string temp_dir = dir;
  string temp_user_dir = parse;
  if (temp_dir == "~") {
    return temp_user_dir;
  }
  if (temp_dir[0] == '~') {
    return temp_user_dir + temp_dir.substr(1);
  }
  return temp_dir;
}

/*
 * Split dir to vector<string>.
 * if input dir start with '~' or '/',
 */
vector<string> splitDir(const char *dir, char *parse) {
  string parsed_dir = parseDir(dir, parse);
  vector<string> split_dir;
  int i = 0;
  int n = parsed_dir.length();
  if (parsed_dir[0] == '/') {
    split_dir.push_back("/");
    i++;
  }
  while (i < n) {
    int j;
    for (j = i; j < n && parsed_dir[j] != '/'; j++);
    string sub = parsed_dir.substr(i, j - i);
    split_dir.push_back(sub);
    i = j + 1;
  }
  return split_dir;
}