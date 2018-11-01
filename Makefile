all:
	@for subdir in examples/*; \
    do \
        ( cd $$subdir && $(MAKE) -f Makefile $@ ) || exit 1; \
    done

clean:
	@for subdir in examples/*; \
    do \
        ( cd $$subdir && $(MAKE) clean -f Makefile $@ ) || exit 1; \
    done
