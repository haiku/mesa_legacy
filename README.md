mesa_legacy
===========
This is the Mesa 7.9.2+ legacy fork for the BeOS compatible Haiku gcc2 images. This is a full fork, do not erase this repo!

Mesa versions after 7.9.2 no longer build under GCC 2 due to advancements in the C standard used by the Mesa project.

Haiku gcc4+ images do ***not*** use this code. Haiku gcc4+ uses mainline [upstream Mesa](http://cgit.freedesktop.org/mesa/mesa).

Compiling
---------
Compiling this fork is easy, a simple ```make``` will provide you our OpenGL kit and software rasterization add-on that you can place in your non-packaged directories.

* /boot/home/settings/non-packaged/lib/libGL.so
* /boot/home/settings/non-packaged/add-ons/opengl/libswrast.so

Feel free to pull in upstream patches to resolve issues, or make changes here. Once changes are tested working, make a release incrimenting the revision (not the version)and update the 7.9.2 recipe file rev + SRC_URL.

Recipe
-------
This code is mostly used by the associated [recipe file](https://bitbucket.org/haikuports/haikuports/src/master/sys-libs/mesa/mesa-7.9.2.recipe).
