#include <stdlib.h>
#include <stdio.h>
#include <xdo.h>

int main (int argc, char *argv[])
{
	Display *dpy = XOpenDisplay (NULL);

	if(dpy == NULL) {
		printf("Can't open display, X may not be running.\n");
		exit(1);
	}
	
	xdo_t *xdo = xdo_new(":0");

	Window root = XDefaultRootWindow (dpy);

	XGrabKey(dpy, 66, AnyModifier, root, False, GrabModeAsync, GrabModeAsync);

	for(;;) {

		XEvent ev;
		XNextEvent (dpy, &ev);

		if(ev.xkey.keycode == 66) {
			if (ev.type == KeyPress) {
				xdo_mouse_down(xdo, CURRENTWINDOW, 1);
			}
			if (ev.type == KeyRelease) {
				xdo_mouse_up(xdo, CURRENTWINDOW, 1);
			}
		}
	}

	return 0;
}
