#pragma once

#include <3dstris/gui.hpp>
#include <3dstris/state.hpp>

class ConfigScreen : public State {
   public:
	ConfigScreen();

	void update(const double dt) override;
	void draw(const bool bottom) override;

   private:
	GUI gui;

	Text tipText;
	Text dasText;
	Text arrText;

	Button& saveButton;
	Button& cancelButton;

	Panel& panel;
	Panel tipPanel;

	DoubleInputField& dasInputField;
	DoubleInputField& arrInputField;

	double getDas() const;
	double getArr() const;
};
