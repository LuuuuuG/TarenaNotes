PROJ   = server
OBJS   = main.o server.o serversocket.o \
		 logthread.o storethread.o clientthread.o \
		 filedao.o oracledao.o logqueue.o
CXX    = g++
LNK    = g++
CFLAGS = -c -Wall -I. -D_DEBUG
RM     = rm -rf
LIBS   = -lpthread #-lclntsh
$(PROJ): $(OBJS)
	$(LNK) $^ $(LIBS) -o $@
.cpp.o:
	$(CXX) $(CFLAGS) $^
clean:
	$(RM) $(PROJ) $(OBJS) *.gch
