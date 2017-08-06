all:
	./node_modules/.bin/madoko index.mdk

clean:
	rm -rf out/

.PHONY: all clean
