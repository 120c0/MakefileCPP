MYDIR = .
list: $(MYDIR)/*
	@for file in $^ ; do \
		${MAKE} -C $${file} ; \
	done
clean: $(MYDIR)/*
	@ for file in $^ ; do \
		${MAKE} -C $${file} clean ; \
	done

