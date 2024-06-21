main.exe: main.c gtk.c main.h
	gcc `pkg-config --cflags gtk+-3.0` -o gtk_app gtk.c main.c `pkg-config --libs gtk+-3.0`