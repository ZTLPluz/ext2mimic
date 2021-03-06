//
// Created by Opynicus on 2022/4/17.
//

#ifndef EXT2MIMIC_VIMIMIC_H
#define EXT2MIMIC_VIMIMIC_H

#include "params.h"

enum editorMode {
  NORMAL, INSERT
};

enum editorKey {
  ESC = 27, LEFT_ARROW = 75, RIGHT_ARROW = 77
};

class vimimic {
 public:
  vimimic();
  //进入编辑
  bool method(char *buf, char *ori_buf, int &cnt, int &max_len);

 protected:
 private:
  int mode;
  int window_x;
  int window_y;
  int cur_x;
  int cur_y;
  HANDLE handle_out;                              //定义一个句柄
  CONSOLE_SCREEN_BUFFER_INFO screen_info;         //定义窗口缓冲区信息结构体
  COORD pos;                             //定义一个坐标结构体
  static void redirectPos(HANDLE hout, int x, int y);

  void moveLeft(const char *buf, int &cnt);

  void moveRight(int &cnt, int &max_len);

  bool delChar(char *buf, int &cnt);
};

#endif //EXT2MIMIC_VIMIMIC_H
