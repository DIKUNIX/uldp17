user:=oleks
server:=dikunix.dk
directory:=uldp17

all:
	./node_modules/.bin/madoko index.mdk

clean:
	rm -rf out/

deploy:
	rsync -avh --delete out/ \
	  $(user)@$(server):/home/$(user)/public_html/$(directory)/

.PHONY: all clean deploy
