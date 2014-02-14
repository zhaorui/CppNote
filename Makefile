SUBDIRS= C

Subdirs: 
	for dir in $(SUBDIRS)
	do
		$(MAKE) -C $$dir
	done


