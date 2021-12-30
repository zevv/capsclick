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
//	XGrabKey(dpy, 105, AnyModifier, root, False, GrabModeAsync, GrabModeAsync);
//	XGrabKey(dpy, 108, AnyModifier, root, False, GrabModeAsync, GrabModeAsync);
	XGrabKey(dpy, 133, AnyModifier, root, False, GrabModeAsync, GrabModeAsync);

	for(;;) {

		XEvent ev;
		XNextEvent (dpy, &ev);

		int c = ev.xkey.keycode;

		if(c == 66 || c == 108) {
			if (ev.type == KeyPress) {
				xdo_mouse_down(xdo, CURRENTWINDOW, 1);
			}
			if (ev.type == KeyRelease) {
				xdo_mouse_up(xdo, CURRENTWINDOW, 1);
			}
		}
		
		if(c == 133 || c == 105) {
			if (ev.type == KeyPress) {
				xdo_mouse_down(xdo, CURRENTWINDOW, 3);
			}
			if (ev.type == KeyRelease) {
				xdo_mouse_up(xdo, CURRENTWINDOW, 3);
			}
		}
	}

	return 0;
}
