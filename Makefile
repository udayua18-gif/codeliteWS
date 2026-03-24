.PHONY: clean All

All:
	@echo "==========Building project:[ project4 -  ]=========="
	@cd "project4" && "$(MAKE)" -f  "project4.mk"
clean:
	@echo "==========Cleaning project:[ project4 -  ]----------"
	@cd "project4" && "$(MAKE)" -f  "project4.mk" clean
