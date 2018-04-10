
Debian
====================
This directory contains files used to package costlyd/costly-qt
for Debian-based Linux systems. If you compile costlyd/costly-qt yourself, there are some useful files here.

## costly: URI support ##


costly-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install costly-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your costly-qt binary to `/usr/bin`
and the `../../share/pixmaps/costly128.png` to `/usr/share/pixmaps`

costly-qt.protocol (KDE)

