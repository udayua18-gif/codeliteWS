.PHONY: clean All

All:
	@echo "==========Building project:[ project6 -  ]=========="
	@cd "project6" && "$(MAKE)" -f  "project6.mk"
clean:
	@echo "==========Cleaning project:[ project6 -  ]----------"
	@cd "project6" && "$(MAKE)" -f  "project6.mk" clean
