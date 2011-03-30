/*
 *  @file GameWindow.h
 *
 *  @date Feb 26, 2011
 *  @author Cedric Wienold
 */

#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

class GameWindow {
   private:
      GameWindow(int w, int h, int x, int y);
      virtual ~GameWindow();

      static GameWindow* pInstance;

      int width, height;
      int xpos, ypos;

   public:
      static GameWindow* Initiate(int w, int h, int x, int y);
      void Destroy();
};

#endif /* GAMEWINDOW_H_ */
