#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrender.h>
#include <fontconfig/fontconfig.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("xftwidth font string\n");
    return 1;
  }

  Display *dpy;
  XftFont *fn;
  XGlyphInfo ext;
  FcChar8 *str; 

  char *name = argv[1];
  size_t len = strlen(argv[2]);
 
  str = (FcChar8*) malloc(len * sizeof(FcChar8));

  strncpy((char*)str, argv[2], len);

  dpy = XOpenDisplay(NULL);
  fn = XftFontOpenName(dpy, 0, name);
 
  if (fn == NULL) {
    printf("Font not found.\n");
    return 1;
  }

  XftTextExtents8(dpy, fn, str, (int)len, &ext);
  printf("%d\n", ext.width);
  return 0;
}
