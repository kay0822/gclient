target1 = helloworld new-helloworld

targets = $(target1)

all: $(targets)
clean:
	rm -f $(targets) *.o

CFLAG_GTK = `pkg-config --libs --cflags gtk+-2.0`
CFLAGS = -g $(CFLAG_GTK)



