PROJ   = client
OBJS   = main.o client.o logreader.o \
		 consolesender.o socketsender.o
CXX    = g++
LNK    = g++
CFLAGS = -c -Wall -I. -D_DEBUG
RM     = rm -rf
$(PROJ): $(OBJS)
	$(LNK) $^ -o $@
.cpp.o:
	$(CXX) $(CFLAGS) $^
clean:
	$(RM) $(PROJ) $(OBJS) *.gch
