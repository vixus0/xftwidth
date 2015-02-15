/*
 * Copyright (C) 2014- Sebastian Fischmeister
 * License: http://www.gnu.org/licenses/gpl.html GPL version 3 or higher
 */

#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrender.h>
#include <fontconfig/fontconfig.h>

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
        if (argc < 4)
        {
                printf("xftsize font string maxwidth\n");
                return 1;
        }

        char *name = argv[1];
        size_t len = strlen(argv[2]);
        char *tryname;

        int maxwidth = 0;
        int trywidth = 10;

        Display *dpy;
        XftFont *fn;
        XGlyphInfo ext;
        FcChar8 str[len]; 

        memcpy(str, argv[2], len);
        sscanf( argv[3],"%d", &maxwidth);
        tryname = malloc(strlen(argv[1])+50);

        dpy = XOpenDisplay(NULL);
        
        while(ext.width < maxwidth)
        {
          	trywidth++;
          	sprintf(tryname,"%s:size=%d",name,trywidth);
          
                fn = XftFontOpenName(dpy, 0, tryname);
          
                if (fn == NULL)
                {
                	puts("Font not found.");
                        return 1;
                }
          
                XftTextExtents8(dpy, fn, str, (int)len, &ext);
        }

        printf("%s\n",tryname);
        XCloseDisplay(dpy);

        return 0;
}
