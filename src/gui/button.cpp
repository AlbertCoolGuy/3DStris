#include <3dstris/gui.hpp>
#include <3dstris/gui/button.hpp>

Button::Button(const GUI& parent, float x, float y, float w, float h,
			   const char* text, std::function<void()> onPress)
	: parent(parent),
	  text("", parent.textCol),
	  x(x),
	  y(y),
	  w(w),
	  h(h),
	  onPress(onPress) {
	this->setText(text);
}

void Button::setText(const char* text) {
	this->text.setText(text);

	auto textWH = this->text.getWH();
	// textW and textH are the text size at scale 1:1, do some math to figure
	// out scale that fits on the button
	// 1   textW
	// - = ----
	// x   w-10
	auto textScale = std::min((w - 10) / textWH.x, 1.0f);

	this->text.setScale({textScale, textScale});

	textWH = this->text.getWH();
	// textW should hopefully be w - 10

	this->text.setPos({x + (w - textWH.x) / 2.0f, y + (h - textWH.y) / 2.0f});
	this->text.setColor(parent.textCol);
}

void Button::draw() const {
	C2D_DrawRectSolid(x, y, 0, w, h,
					  pressed ? parent.pressedCol : parent.primaryCol);
	this->text.draw();
}

void Button::update(touchPosition touch) {
	pressed = inside(touch.px, touch.py);
}

bool Button::inside(float posX, float posY) const {
	return posX > x && posX < x + w &&  //
		   posY > y && posY < y + h;
}

void Button::press() {
	onPress();
}