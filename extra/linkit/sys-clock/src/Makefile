all: lcd-time

lcd-time: lcd-time.cxx
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -r *.o lcd-time

.PHONY: all clean lcd-time
