//header for background momement

#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int pic_x, pic_y;
int dx, dy;

void objectChange() {
	pic_x += dx;
	pic_y += dy;

	if (pic_x >= 500 || pic_x <= 0)
		dx = -dx;
	if (pic_y >= 500 || pic_y <= 0)
		dy = -dy;
}

#endif // !MYHEADER_H_INCLUDED