all:
	@for subdir in examples/*; \
    do \
        if [ -d $$subdir ]; then \
            ( cd $$subdir && $(MAKE) -f Makefile $@ ) || exit 1; \
        fi \
    done

clean:
	@for subdir in examples/*; \
    do \
        if [ -d $$subdir ]; then \
            ( cd $$subdir && $(MAKE) clean -f Makefile $@ ) || exit 1; \
        fi \
    done
