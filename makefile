all:
	@ find . -type d -name 'ex*' -exec make -s -C {} \;

clean:
	@ find . -type d -name 'ex*' -exec make -s -C {} clean \;

fclean:
	@ find . -type d -name 'ex*' -exec make -s -C {} fclean \;
re:
	@ find . -type d -name 'ex*' -exec make -s -C {} re \;
