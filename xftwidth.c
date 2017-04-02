#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrender.h>
#include <fontconfig/fontconfig.h>

#include <stdio.h>
#include <string.h>

XftFont *Load(Display *dpy, char *name, double size) {
  return XftFontOpen(
        dpy, 0,
        XFT_FAMILY, XftTypeString, name,
        XFT_SIZE, XftTypeDouble, size,
        NULL
        );
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    printf("xftwidth font string [maxwidth]\n");
    return 1;
  }

  char *name = argv[1];
  size_t name_len = strlen(name);
  size_t len = strlen(argv[2]);
  int maxwidth = 0;
  double fontsize = 1.0;
  double sizeincr = 1.0;

  Display *dpy;
  XftFont *fn;
  XGlyphInfo ext;
  FcChar8 str[len];

  memcpy(str, argv[2], len);
  dpy = XOpenDisplay(NULL);

  if (argc > 3) {
    sscanf(argv[3], "%d", &maxwidth);

    if (maxwidth <= 0) {
      puts("maxwidth must be > 0.");
      return 1;
    }

    fn = Load(dpy, name, fontsize);
  } else {
    fn = XftFontOpenName(dpy, 0, name);
  }

  if (fn == NULL)
  {
    puts("Font not found.");
    return 1;
  }

  XftTextExtentsUtf8(dpy, fn, str, (int)len, &ext);

  if (maxwidth > 0) {
    while (ext.width < maxwidth) {
      fontsize += sizeincr;
      fn = Load(dpy, name, fontsize);
      XftTextExtentsUtf8(dpy, fn, str, (int)len, &ext);
    }

    printf("%s:size=%.0f ", name, fontsize);
  }

  printf("%d\n", ext.width);
  XftFontClose(dpy, fn);
  XCloseDisplay(dpy);

  return 0;
}
