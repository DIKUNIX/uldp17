user:=oleks
server:=dikunix.dk
directory:=uldp17
madoko:=./node_modules/.bin/madoko
index:=index.mdk

all:
	$(madoko) $(index)

pdf:
	$(madoko) --pdf $(index)

clean:
	rm -rf out/

deploy:
	rsync -avh --delete out/ \
	  $(user)@$(server):/home/$(user)/public_html/$(directory)/

deploy-onlineta:
	rsync -avh --delete out/ \
	  root@uldp17.onlineta.org:/var/www/html

.PHONY: all clean deploy
