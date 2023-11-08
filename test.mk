MAKE_ARGV=$(MAKECMDGOALS)
MAKE_ARGC="$(words $(MAKECMDGOALS))"
MAKE_ARGV_FILTER=$(filter-out $@,$(MAKECMDGOALS))#
MAKE_ARGC_FILTER="$(words $(MAKE_ARGV_FILTER))"

.PHONY: test
test:
	@echo "MAKE_ARGV=[$(MAKE_ARGV)], MAKE_ARGC=[$(MAKE_ARGC)], MAKE_ARGV_FILTER=[${MAKE_ARGV_FILTER}], MAKE_ARGC_FILTER=[$(MAKE_ARGC_FILTER)]"

ifeq ("$(MAKE_ARGV)", "")
	@echo "MAKE_ARGV is empty !!!"
else
	@echo "MAKE_ARGV isn't empty !!!"
endif

ifeq ("$(MAKE_ARGC)", "0")
	@echo "MAKE_ARGC is equal to 0 !!!"
else
	@echo "MAKE_ARGC isn't equal to 0 !!!"
endif

ifeq ("$(MAKE_ARGV_FILTER)", "")
	@echo "MAKE_ARGV_FILTER is NULL !!!"
else
	@echo "MAKE_ARGV_FILTER isn't empty !!!"
endif

ifeq ("$(MAKE_ARGC_FILTER)", "0")
	@echo "MAKE_ARGC_FILTER is 0 !!!"
else
	@echo "MAKE_ARGC_FILTER isn't equal to 0 !!!"
endif
