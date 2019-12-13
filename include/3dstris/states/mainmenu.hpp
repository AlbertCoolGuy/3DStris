#pragma once

#include <citro2d.h>
#include <3dstris/gui.hpp>
#include <3dstris/state.hpp>
#include <3dstris/states/playing.hpp>
#include <3dstris/util.hpp>

class MainMenu : public State {
   public:
	MainMenu();

	void update(double dt) override;
	void draw(bool bottom) override;

   private:
	Text versionText;

	C2D_Image icon;

	Color colBackground;

	GUI gui;
};