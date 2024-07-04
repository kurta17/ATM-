CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -I.
LIBS = `pkg-config --libs gtk+-3.0`

all: gtk_app

gtk_app: main.o gtk.o gtk_withdraw.o
	$(CC) $(CFLAGS) -o gtk_app main.o gtk.o gtk_withdraw.o $(LIBS)

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

gtk.o: gtk.c main.h
	$(CC) $(CFLAGS) -c gtk.c

gtk_withdraw.o: gtk_withdraw.s
	$(CC) -c gtk_withdraw.s -o gtk_withdraw.o

clean:
	rm -f *.o gtk_app
